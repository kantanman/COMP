// myls.c ... my very own "ls" implementation

#include <sys/types.h>
#include <sys/stat.h>

#include <dirent.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __linux__
# include <bsd/string.h>
#endif
#include <sysexits.h>
#include <unistd.h>

#define MAXDIRNAME 256
#define MAXFNAME 256
#define MAXNAME 24

char *rwxmode (mode_t, char *);
char *username (uid_t, char *);
char *groupname (gid_t, char *);

int main (int argc, char *argv[])
{
	// string buffers for various names
	// char uname[MAXNAME+1]; // UNCOMMENT this line
	// char gname[MAXNAME+1]; // UNCOMMENT this line
	// char mode[MAXNAME+1]; // UNCOMMENT this line

	// collect the directory name, with "." as default
	char dirname[MAXDIRNAME] = ".";
	if (argc >= 2)
		strlcpy (dirname, argv[1], MAXDIRNAME);

	// check that the name really is a directory
	struct stat info;
	if (stat (dirname, &info) < 0)
		err (EX_OSERR, "%s", dirname);

	if (! S_ISDIR (info.st_mode)) {
		errno = ENOTDIR;
		err (EX_DATAERR, "%s", dirname);
	}

        DIR *df;
        df = opendir(dirname);

        // read directory entries
        struct dirent *entry; // UNCOMMENT this line
        entry = readdir(df);
        struct stat metadata;

        while((entry = readdir(df)) != NULL) {
            char *name = entry->d_name;
            if(name[0] == '.') continue;
            // finding out typefils
            lstat(dirname, &metadata);
            printf   (" %s %-8.8s %-8.8s %8lld %s\n",
                     rwxmode (metadata.st_mode, name),
                     username (metadata.st_uid, name),
                     groupname (metadata.st_gid, name),
                     (long long) metadata.st_size, name
            );

        }

        //finishing up
        closedir(df);

	return EXIT_SUCCESS;
}

// convert octal mode to -rwxrwxrwx string
char *rwxmode (mode_t mode, char *str)
{
//Filetype character
        switch(mode & S_IFMT) {
           case S_IFDIR:  strcat(str, "d");            break;
           case S_IFLNK:  strcat(str, "l");            break;
           case S_IFREG:  strcat(str, "_");            break;
           default:       strcat(str, "?");            break;
        }

        // owner
        switch(mode & S_IRWXU) {
           case S_IRWXU:  strcat(str, "rwx");            break;  
           case S_IRUSR:  strcat(str, "r--");            break;  
           case S_IWUSR:  strcat(str, "-w-");            break;  
           case S_IXUSR:  strcat(str, "--x");            break;
           case 00300:    strcat(str, "-wx");            break;
           case 00500:    strcat(str, "r-x");            break;
           case 00600:    strcat(str, "rw-");            break; 
           default:       strcat(str, "---");            break;  
        }

        // group
        switch(mode & S_IRWXG) {
           case S_IRWXG:  strcat(str, "rwx");            break;
           case S_IRGRP:  strcat(str, "r--");            break;
           case S_IWGRP:  strcat(str, "-x-");            break;
           case S_IXGRP:  strcat(str, "-x-");            break;
           case 00030:    strcat(str, "-wx");            break;
           case 00050:    strcat(str, "r-x");            break;
           case 00060:    strcat(str, "rw-");            break;
           default:       strcat(str, "---");            break; 
        }
        
        // other
        switch(mode & S_IRWXO) {
           case S_IRWXO:  strcat(str, "rwx");            break;
           case S_IROTH:  strcat(str, "r--");            break;
           case S_IWOTH:  strcat(str, "-x-");            break;
           case S_IXOTH:  strcat(str, "-x-");            break;
           case 00003:    strcat(str, "-wx");            break;
           case 00005:    strcat(str, "r-x");            break;
           case 00006:    strcat(str, "rw-");            break;
           default:       strcat(str, "---");            break;
        }

        return str;

}

// convert user id to user name
char *username (uid_t uid, char *name)
{
	struct passwd *uinfo = getpwuid (uid);
	if (uinfo != NULL)
		snprintf (name, MAXNAME, "%s", uinfo->pw_name);
	else
		snprintf (name, MAXNAME, "%d?", (int) uid);
	return name;
}

// convert group id to group name
char *groupname (gid_t gid, char *name)
{
	struct group *ginfo = getgrgid (gid);
	if (ginfo != NULL)
		snprintf (name, MAXNAME, "%s", ginfo->gr_name);
	else
		snprintf (name, MAXNAME, "%d?", (int) gid);
	return name;
}
