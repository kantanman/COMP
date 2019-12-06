// Assignment 2 19T1 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by EUGENE CLARK (z5258551)
// on 1-5-19
//
// Version 1.0.0: Assignment released.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "pokedex.h"

// Add your own #defines here.

#define DELAY_1 0//300000
#define DELAY_2 0//1500000
#define DELAY_3 0//1
#define DELAY_4 0//2
#define BULBASAUR_ID 1
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE POISON_TYPE
#define BULBASAUR_SECOND_TYPE GRASS_TYPE

#define IVYSAUR_ID 2
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE POISON_TYPE
#define IVYSAUR_SECOND_TYPE GRASS_TYPE

#define VENUSAUR_ID 3
#define VENUSAUR_NAME "Venusaur"
#define VENUSAUR_HEIGHT 2.0
#define VENUSAUR_WEIGHT 100.0
#define VENUSAUR_FIRST_TYPE POISON_TYPE
#define VENUSAUR_SECOND_TYPE GRASS_TYPE

#define CHARMANDER_ID 4
#define CHARMANDER_NAME "Charmander"
#define CHARMANDER_HEIGHT 0.6
#define CHARMANDER_WEIGHT 8.5
#define CHARMANDER_FIRST_TYPE FIRE_TYPE
#define CHARMANDER_SECOND_TYPE NONE_TYPE

#define CHARMELEON_ID 5
#define CHARMELEON_NAME "Charmeleon"
#define CHARMELEON_HEIGHT 1.1
#define CHARMELEON_WEIGHT 19.0
#define CHARMELEON_FIRST_TYPE FIRE_TYPE
#define CHARMELEON_SECOND_TYPE NONE_TYPE

#define CHARIZARD_ID 6
#define CHARIZARD_NAME "Charizard"
#define CHARIZARD_HEIGHT 1.7
#define CHARIZARD_WEIGHT 90.5
#define CHARIZARD_FIRST_TYPE FLYING_TYPE
#define CHARIZARD_SECOND_TYPE FIRE_TYPE

#define SQUIRTLE_ID 7
#define SQUIRTLE_NAME "Squirtle"
#define SQUIRTLE_HEIGHT 0.5
#define SQUIRTLE_WEIGHT 9.0
#define SQUIRTLE_FIRST_TYPE WATER_TYPE
#define SQUIRTLE_SECOND_TYPE NONE_TYPE

#define WARTORTLE_ID 8
#define WARTORTLE_NAME "Wartortle"
#define WARTORTLE_HEIGHT 1.0
#define WARTORTLE_WEIGHT 22.5
#define WARTORTLE_FIRST_TYPE WATER_TYPE
#define WARTORTLE_SECOND_TYPE NONE_TYPE

#define BLASTOISE_ID 9
#define BLASTOISE_NAME "Blastoise"
#define BLASTOISE_HEIGHT 1.6
#define BLASTOISE_WEIGHT 85.5
#define BLASTOISE_FIRST_TYPE WATER_TYPE
#define BLASTOISE_SECOND_TYPE NONE_TYPE

#define CATERPIE_ID 10
#define CATERPIE_NAME "Caterpie"
#define CATERPIE_HEIGHT 0.3
#define CATERPIE_WEIGHT 2.9
#define CATERPIE_FIRST_TYPE BUG_TYPE
#define CATERPIE_SECOND_TYPE NONE_TYPE

#define METAPOD_ID 11
#define METAPOD_NAME "Metapod"
#define METAPOD_HEIGHT 0.7
#define METAPOD_WEIGHT 9.9
#define METAPOD_FIRST_TYPE BUG_TYPE
#define METAPOD_SECOND_TYPE NONE_TYPE

#define BUTTERFREE_ID 12
#define BUTTERFREE_NAME "Butterfree"
#define BUTTERFREE_HEIGHT 1.1
#define BUTTERFREE_WEIGHT 32.0
#define BUTTERFREE_FIRST_TYPE FLYING_TYPE
#define BUTTERFREE_SECOND_TYPE BUG_TYPE

#define WEEDLE_ID 13
#define WEEDLE_NAME "Weedle"
#define WEEDLE_HEIGHT 0.3
#define WEEDLE_WEIGHT 3.2
#define WEEDLE_FIRST_TYPE POISON_TYPE
#define WEEDLE_SECOND_TYPE BUG_TYPE

#define KAKUNA_ID 14
#define KAKUNA_NAME "Kakuna"
#define KAKUNA_HEIGHT 0.6
#define KAKUNA_WEIGHT 10.0
#define KAKUNA_FIRST_TYPE POISON_TYPE
#define KAKUNA_SECOND_TYPE BUG_TYPE

#define BEEDRILL_ID 15
#define BEEDRILL_NAME "Beedrill"
#define BEEDRILL_HEIGHT 1.0
#define BEEDRILL_WEIGHT 29.5
#define BEEDRILL_FIRST_TYPE POISON_TYPE
#define BEEDRILL_SECOND_TYPE BUG_TYPE

#define PIDGEY_ID 16
#define PIDGEY_NAME "Pidgey"
#define PIDGEY_HEIGHT 0.3
#define PIDGEY_WEIGHT 1.8
#define PIDGEY_FIRST_TYPE FLYING_TYPE
#define PIDGEY_SECOND_TYPE NORMAL_TYPE

#define PIDGEOTTO_ID 17
#define PIDGEOTTO_NAME "Pidgeotto"
#define PIDGEOTTO_HEIGHT 1.1
#define PIDGEOTTO_WEIGHT 30.0
#define PIDGEOTTO_FIRST_TYPE FLYING_TYPE
#define PIDGEOTTO_SECOND_TYPE NORMAL_TYPE

#define PIDGEOT_ID 18
#define PIDGEOT_NAME "Pidgeot"
#define PIDGEOT_HEIGHT 1.5
#define PIDGEOT_WEIGHT 39.5
#define PIDGEOT_FIRST_TYPE FLYING_TYPE
#define PIDGEOT_SECOND_TYPE NORMAL_TYPE

#define RATTATA_ID 19
#define RATTATA_NAME "Rattata"
#define RATTATA_HEIGHT 0.3
#define RATTATA_WEIGHT 3.5
#define RATTATA_FIRST_TYPE NORMAL_TYPE
#define RATTATA_SECOND_TYPE NONE_TYPE

#define RATICATE_ID 20
#define RATICATE_NAME "Raticate"
#define RATICATE_HEIGHT 0.7
#define RATICATE_WEIGHT 18.5
#define RATICATE_FIRST_TYPE NORMAL_TYPE
#define RATICATE_SECOND_TYPE NONE_TYPE

#define SPEAROW_ID 21
#define SPEAROW_NAME "Spearow"
#define SPEAROW_HEIGHT 0.3
#define SPEAROW_WEIGHT 2.0
#define SPEAROW_FIRST_TYPE FLYING_TYPE
#define SPEAROW_SECOND_TYPE NORMAL_TYPE

#define FEAROW_ID 22
#define FEAROW_NAME "Fearow"
#define FEAROW_HEIGHT 1.2
#define FEAROW_WEIGHT 38.0
#define FEAROW_FIRST_TYPE FLYING_TYPE
#define FEAROW_SECOND_TYPE NORMAL_TYPE

#define EKANS_ID 23
#define EKANS_NAME "Ekans"
#define EKANS_HEIGHT 2.0
#define EKANS_WEIGHT 6.9
#define EKANS_FIRST_TYPE POISON_TYPE
#define EKANS_SECOND_TYPE NONE_TYPE

#define ARBOK_ID 24
#define ARBOK_NAME "Arbok"
#define ARBOK_HEIGHT 3.5
#define ARBOK_WEIGHT 65.0
#define ARBOK_FIRST_TYPE POISON_TYPE
#define ARBOK_SECOND_TYPE NONE_TYPE

#define PIKACHU_ID 25
#define PIKACHU_NAME "Pikachu"
#define PIKACHU_HEIGHT 0.4
#define PIKACHU_WEIGHT 6.0
#define PIKACHU_FIRST_TYPE ELECTRIC_TYPE
#define PIKACHU_SECOND_TYPE NONE_TYPE

#define RAICHU_ID 26
#define RAICHU_NAME "Raichu"
#define RAICHU_HEIGHT 0.8
#define RAICHU_WEIGHT 30.0
#define RAICHU_FIRST_TYPE ELECTRIC_TYPE
#define RAICHU_SECOND_TYPE NONE_TYPE

#define SANDSHREW_ID 27
#define SANDSHREW_NAME "Sandshrew"
#define SANDSHREW_HEIGHT 0.6
#define SANDSHREW_WEIGHT 12.0
#define SANDSHREW_FIRST_TYPE GROUND_TYPE
#define SANDSHREW_SECOND_TYPE NONE_TYPE

#define SANDSLASH_ID 28
#define SANDSLASH_NAME "Sandslash"
#define SANDSLASH_HEIGHT 1.0
#define SANDSLASH_WEIGHT 29.5
#define SANDSLASH_FIRST_TYPE GROUND_TYPE
#define SANDSLASH_SECOND_TYPE NONE_TYPE

#define NIDORANF_ID 29
#define NIDORANF_NAME "Nidoranf"
#define NIDORANF_HEIGHT 0.4
#define NIDORANF_WEIGHT 7.0
#define NIDORANF_FIRST_TYPE POISON_TYPE
#define NIDORANF_SECOND_TYPE NONE_TYPE

#define NIDORINA_ID 30
#define NIDORINA_NAME "Nidorina"
#define NIDORINA_HEIGHT 0.8
#define NIDORINA_WEIGHT 20.0
#define NIDORINA_FIRST_TYPE POISON_TYPE
#define NIDORINA_SECOND_TYPE NONE_TYPE

#define NIDOQUEEN_ID 31
#define NIDOQUEEN_NAME "Nidoqueen"
#define NIDOQUEEN_HEIGHT 1.3
#define NIDOQUEEN_WEIGHT 60.0
#define NIDOQUEEN_FIRST_TYPE GROUND_TYPE
#define NIDOQUEEN_SECOND_TYPE POISON_TYPE

#define NIDORANM_ID 32
#define NIDORANM_NAME "Nidoranm"
#define NIDORANM_HEIGHT 0.5
#define NIDORANM_WEIGHT 9.0
#define NIDORANM_FIRST_TYPE POISON_TYPE
#define NIDORANM_SECOND_TYPE NONE_TYPE

#define NIDORINO_ID 33
#define NIDORINO_NAME "Nidorino"
#define NIDORINO_HEIGHT 0.9
#define NIDORINO_WEIGHT 19.5
#define NIDORINO_FIRST_TYPE POISON_TYPE
#define NIDORINO_SECOND_TYPE NONE_TYPE

#define NIDOKING_ID 34
#define NIDOKING_NAME "Nidoking"
#define NIDOKING_HEIGHT 1.4
#define NIDOKING_WEIGHT 62.0
#define NIDOKING_FIRST_TYPE GROUND_TYPE
#define NIDOKING_SECOND_TYPE POISON_TYPE

#define CLEFAIRY_ID 35
#define CLEFAIRY_NAME "Clefairy"
#define CLEFAIRY_HEIGHT 0.6
#define CLEFAIRY_WEIGHT 7.5
#define CLEFAIRY_FIRST_TYPE FAIRY_TYPE
#define CLEFAIRY_SECOND_TYPE NONE_TYPE

#define CLEFABLE_ID 36
#define CLEFABLE_NAME "Clefable"
#define CLEFABLE_HEIGHT 1.3
#define CLEFABLE_WEIGHT 40.0
#define CLEFABLE_FIRST_TYPE FAIRY_TYPE
#define CLEFABLE_SECOND_TYPE NONE_TYPE

#define VULPIX_ID 37
#define VULPIX_NAME "Vulpix"
#define VULPIX_HEIGHT 0.6
#define VULPIX_WEIGHT 9.9
#define VULPIX_FIRST_TYPE FIRE_TYPE
#define VULPIX_SECOND_TYPE NONE_TYPE

#define NINETALES_ID 38
#define NINETALES_NAME "Ninetales"
#define NINETALES_HEIGHT 1.1
#define NINETALES_WEIGHT 19.9
#define NINETALES_FIRST_TYPE FIRE_TYPE
#define NINETALES_SECOND_TYPE NONE_TYPE

#define JIGGLYPUFF_ID 39
#define JIGGLYPUFF_NAME "Jigglypuff"
#define JIGGLYPUFF_HEIGHT 0.5
#define JIGGLYPUFF_WEIGHT 5.5
#define JIGGLYPUFF_FIRST_TYPE FAIRY_TYPE
#define JIGGLYPUFF_SECOND_TYPE NORMAL_TYPE

#define WIGGLYTUFF_ID 40
#define WIGGLYTUFF_NAME "Wigglytuff"
#define WIGGLYTUFF_HEIGHT 1.0
#define WIGGLYTUFF_WEIGHT 12.0
#define WIGGLYTUFF_FIRST_TYPE FAIRY_TYPE
#define WIGGLYTUFF_SECOND_TYPE NORMAL_TYPE

#define ZUBAT_ID 41
#define ZUBAT_NAME "Zubat"
#define ZUBAT_HEIGHT 0.8
#define ZUBAT_WEIGHT 7.5
#define ZUBAT_FIRST_TYPE FLYING_TYPE
#define ZUBAT_SECOND_TYPE POISON_TYPE

#define GOLBAT_ID 42
#define GOLBAT_NAME "Golbat"
#define GOLBAT_HEIGHT 1.6
#define GOLBAT_WEIGHT 55.0
#define GOLBAT_FIRST_TYPE FLYING_TYPE
#define GOLBAT_SECOND_TYPE POISON_TYPE

#define ODDISH_ID 43
#define ODDISH_NAME "Oddish"
#define ODDISH_HEIGHT 0.5
#define ODDISH_WEIGHT 5.4
#define ODDISH_FIRST_TYPE POISON_TYPE
#define ODDISH_SECOND_TYPE GRASS_TYPE

#define GLOOM_ID 44
#define GLOOM_NAME "Gloom"
#define GLOOM_HEIGHT 0.8
#define GLOOM_WEIGHT 8.6
#define GLOOM_FIRST_TYPE POISON_TYPE
#define GLOOM_SECOND_TYPE GRASS_TYPE

#define VILEPLUME_ID 45
#define VILEPLUME_NAME "Vileplume"
#define VILEPLUME_HEIGHT 1.2
#define VILEPLUME_WEIGHT 18.6
#define VILEPLUME_FIRST_TYPE POISON_TYPE
#define VILEPLUME_SECOND_TYPE GRASS_TYPE

#define PARAS_ID 46
#define PARAS_NAME "Paras"
#define PARAS_HEIGHT 0.3
#define PARAS_WEIGHT 5.4
#define PARAS_FIRST_TYPE GRASS_TYPE
#define PARAS_SECOND_TYPE BUG_TYPE

#define PARASECT_ID 47
#define PARASECT_NAME "Parasect"
#define PARASECT_HEIGHT 1.0
#define PARASECT_WEIGHT 29.5
#define PARASECT_FIRST_TYPE GRASS_TYPE
#define PARASECT_SECOND_TYPE BUG_TYPE

#define VENONAT_ID 48
#define VENONAT_NAME "Venonat"
#define VENONAT_HEIGHT 1.0
#define VENONAT_WEIGHT 30.0
#define VENONAT_FIRST_TYPE POISON_TYPE
#define VENONAT_SECOND_TYPE BUG_TYPE

#define VENOMOTH_ID 49
#define VENOMOTH_NAME "Venomoth"
#define VENOMOTH_HEIGHT 1.5
#define VENOMOTH_WEIGHT 12.5
#define VENOMOTH_FIRST_TYPE POISON_TYPE
#define VENOMOTH_SECOND_TYPE BUG_TYPE

#define DIGLETT_ID 50
#define DIGLETT_NAME "Diglett"
#define DIGLETT_HEIGHT 0.2
#define DIGLETT_WEIGHT 0.8
#define DIGLETT_FIRST_TYPE GROUND_TYPE
#define DIGLETT_SECOND_TYPE NONE_TYPE

#define DUGTRIO_ID 51
#define DUGTRIO_NAME "Dugtrio"
#define DUGTRIO_HEIGHT 0.7
#define DUGTRIO_WEIGHT 33.3
#define DUGTRIO_FIRST_TYPE GROUND_TYPE
#define DUGTRIO_SECOND_TYPE NONE_TYPE

#define MEOWTH_ID 52
#define MEOWTH_NAME "Meowth"
#define MEOWTH_HEIGHT 0.4
#define MEOWTH_WEIGHT 4.2
#define MEOWTH_FIRST_TYPE NORMAL_TYPE
#define MEOWTH_SECOND_TYPE NONE_TYPE

#define PERSIAN_ID 53
#define PERSIAN_NAME "Persian"
#define PERSIAN_HEIGHT 1.0
#define PERSIAN_WEIGHT 32.0
#define PERSIAN_FIRST_TYPE NORMAL_TYPE
#define PERSIAN_SECOND_TYPE NONE_TYPE

#define PSYDUCK_ID 54
#define PSYDUCK_NAME "Psyduck"
#define PSYDUCK_HEIGHT 0.8
#define PSYDUCK_WEIGHT 19.6
#define PSYDUCK_FIRST_TYPE WATER_TYPE
#define PSYDUCK_SECOND_TYPE NONE_TYPE

#define GOLDUCK_ID 55
#define GOLDUCK_NAME "Golduck"
#define GOLDUCK_HEIGHT 1.7
#define GOLDUCK_WEIGHT 76.6
#define GOLDUCK_FIRST_TYPE WATER_TYPE
#define GOLDUCK_SECOND_TYPE NONE_TYPE

#define MANKEY_ID 56
#define MANKEY_NAME "Mankey"
#define MANKEY_HEIGHT 0.5
#define MANKEY_WEIGHT 28.0
#define MANKEY_FIRST_TYPE FIGHTING_TYPE
#define MANKEY_SECOND_TYPE NONE_TYPE

#define PRIMEAPE_ID 57
#define PRIMEAPE_NAME "Primeape"
#define PRIMEAPE_HEIGHT 1.0
#define PRIMEAPE_WEIGHT 32.0
#define PRIMEAPE_FIRST_TYPE FIGHTING_TYPE
#define PRIMEAPE_SECOND_TYPE NONE_TYPE

#define GROWLITHE_ID 58
#define GROWLITHE_NAME "Growlithe"
#define GROWLITHE_HEIGHT 0.7
#define GROWLITHE_WEIGHT 19.0
#define GROWLITHE_FIRST_TYPE FIRE_TYPE
#define GROWLITHE_SECOND_TYPE NONE_TYPE

#define ARCANINE_ID 59
#define ARCANINE_NAME "Arcanine"
#define ARCANINE_HEIGHT 1.9
#define ARCANINE_WEIGHT 155.0
#define ARCANINE_FIRST_TYPE FIRE_TYPE
#define ARCANINE_SECOND_TYPE NONE_TYPE

#define POLIWAG_ID 60
#define POLIWAG_NAME "Poliwag"
#define POLIWAG_HEIGHT 0.6
#define POLIWAG_WEIGHT 12.4
#define POLIWAG_FIRST_TYPE WATER_TYPE
#define POLIWAG_SECOND_TYPE NONE_TYPE

#define POLIWHIRL_ID 61
#define POLIWHIRL_NAME "Poliwhirl"
#define POLIWHIRL_HEIGHT 1.0
#define POLIWHIRL_WEIGHT 20.0
#define POLIWHIRL_FIRST_TYPE WATER_TYPE
#define POLIWHIRL_SECOND_TYPE NONE_TYPE

#define POLIWRATH_ID 62
#define POLIWRATH_NAME "Poliwrath"
#define POLIWRATH_HEIGHT 1.3
#define POLIWRATH_WEIGHT 54.0
#define POLIWRATH_FIRST_TYPE FIGHTING_TYPE
#define POLIWRATH_SECOND_TYPE WATER_TYPE

#define ABRA_ID 63
#define ABRA_NAME "Abra"
#define ABRA_HEIGHT 0.9
#define ABRA_WEIGHT 19.5
#define ABRA_FIRST_TYPE PSYCHIC_TYPE
#define ABRA_SECOND_TYPE NONE_TYPE

#define KADABRA_ID 64
#define KADABRA_NAME "Kadabra"
#define KADABRA_HEIGHT 1.3
#define KADABRA_WEIGHT 56.5
#define KADABRA_FIRST_TYPE PSYCHIC_TYPE
#define KADABRA_SECOND_TYPE NONE_TYPE

#define ALAKAZAM_ID 65
#define ALAKAZAM_NAME "Alakazam"
#define ALAKAZAM_HEIGHT 1.5
#define ALAKAZAM_WEIGHT 48.0
#define ALAKAZAM_FIRST_TYPE PSYCHIC_TYPE
#define ALAKAZAM_SECOND_TYPE NONE_TYPE

#define MACHOP_ID 66
#define MACHOP_NAME "Machop"
#define MACHOP_HEIGHT 0.8
#define MACHOP_WEIGHT 19.5
#define MACHOP_FIRST_TYPE FIGHTING_TYPE
#define MACHOP_SECOND_TYPE NONE_TYPE

#define MACHOKE_ID 67
#define MACHOKE_NAME "Machoke"
#define MACHOKE_HEIGHT 1.5
#define MACHOKE_WEIGHT 70.5
#define MACHOKE_FIRST_TYPE FIGHTING_TYPE
#define MACHOKE_SECOND_TYPE NONE_TYPE

#define MACHAMP_ID 68
#define MACHAMP_NAME "Machamp"
#define MACHAMP_HEIGHT 1.6
#define MACHAMP_WEIGHT 130.0
#define MACHAMP_FIRST_TYPE FIGHTING_TYPE
#define MACHAMP_SECOND_TYPE NONE_TYPE

#define BELLSPROUT_ID 69
#define BELLSPROUT_NAME "Bellsprout"
#define BELLSPROUT_HEIGHT 0.7
#define BELLSPROUT_WEIGHT 4.0
#define BELLSPROUT_FIRST_TYPE POISON_TYPE
#define BELLSPROUT_SECOND_TYPE GRASS_TYPE

#define WEEPINBELL_ID 70
#define WEEPINBELL_NAME "Weepinbell"
#define WEEPINBELL_HEIGHT 1.0
#define WEEPINBELL_WEIGHT 6.4
#define WEEPINBELL_FIRST_TYPE POISON_TYPE
#define WEEPINBELL_SECOND_TYPE GRASS_TYPE

#define VICTREEBEL_ID 71
#define VICTREEBEL_NAME "Victreebel"
#define VICTREEBEL_HEIGHT 1.7
#define VICTREEBEL_WEIGHT 15.5
#define VICTREEBEL_FIRST_TYPE POISON_TYPE
#define VICTREEBEL_SECOND_TYPE GRASS_TYPE

#define TENTACOOL_ID 72
#define TENTACOOL_NAME "Tentacool"
#define TENTACOOL_HEIGHT 0.9
#define TENTACOOL_WEIGHT 45.5
#define TENTACOOL_FIRST_TYPE POISON_TYPE
#define TENTACOOL_SECOND_TYPE WATER_TYPE

#define TENTACRUEL_ID 73
#define TENTACRUEL_NAME "Tentacruel"
#define TENTACRUEL_HEIGHT 1.6
#define TENTACRUEL_WEIGHT 55.0
#define TENTACRUEL_FIRST_TYPE POISON_TYPE
#define TENTACRUEL_SECOND_TYPE WATER_TYPE

#define GEODUDE_ID 74
#define GEODUDE_NAME "Geodude"
#define GEODUDE_HEIGHT 0.4
#define GEODUDE_WEIGHT 20.0
#define GEODUDE_FIRST_TYPE GROUND_TYPE
#define GEODUDE_SECOND_TYPE ROCK_TYPE

#define GRAVELER_ID 75
#define GRAVELER_NAME "Graveler"
#define GRAVELER_HEIGHT 1.0
#define GRAVELER_WEIGHT 105.0
#define GRAVELER_FIRST_TYPE GROUND_TYPE
#define GRAVELER_SECOND_TYPE ROCK_TYPE

#define GOLEM_ID 76
#define GOLEM_NAME "Golem"
#define GOLEM_HEIGHT 1.4
#define GOLEM_WEIGHT 300.0
#define GOLEM_FIRST_TYPE GROUND_TYPE
#define GOLEM_SECOND_TYPE ROCK_TYPE

#define PONYTA_ID 77
#define PONYTA_NAME "Ponyta"
#define PONYTA_HEIGHT 1.0
#define PONYTA_WEIGHT 30.0
#define PONYTA_FIRST_TYPE FIRE_TYPE
#define PONYTA_SECOND_TYPE NONE_TYPE

#define RAPIDASH_ID 78
#define RAPIDASH_NAME "Rapidash"
#define RAPIDASH_HEIGHT 1.7
#define RAPIDASH_WEIGHT 95.0
#define RAPIDASH_FIRST_TYPE FIRE_TYPE
#define RAPIDASH_SECOND_TYPE NONE_TYPE

#define SLOWPOKE_ID 79
#define SLOWPOKE_NAME "Slowpoke"
#define SLOWPOKE_HEIGHT 1.2
#define SLOWPOKE_WEIGHT 36.0
#define SLOWPOKE_FIRST_TYPE PSYCHIC_TYPE
#define SLOWPOKE_SECOND_TYPE WATER_TYPE

#define SLOWBRO_ID 80
#define SLOWBRO_NAME "Slowbro"
#define SLOWBRO_HEIGHT 1.6
#define SLOWBRO_WEIGHT 78.5
#define SLOWBRO_FIRST_TYPE PSYCHIC_TYPE
#define SLOWBRO_SECOND_TYPE WATER_TYPE

#define MAGNEMITE_ID 81
#define MAGNEMITE_NAME "Magnemite"
#define MAGNEMITE_HEIGHT 0.3
#define MAGNEMITE_WEIGHT 6.0
#define MAGNEMITE_FIRST_TYPE STEEL_TYPE
#define MAGNEMITE_SECOND_TYPE ELECTRIC_TYPE

#define MAGNETON_ID 82
#define MAGNETON_NAME "Magneton"
#define MAGNETON_HEIGHT 1.0
#define MAGNETON_WEIGHT 60.0
#define MAGNETON_FIRST_TYPE STEEL_TYPE
#define MAGNETON_SECOND_TYPE ELECTRIC_TYPE

#define FARFETCHD_ID 83
#define FARFETCHD_NAME "Farfetchd"
#define FARFETCHD_HEIGHT 0.8
#define FARFETCHD_WEIGHT 15.0
#define FARFETCHD_FIRST_TYPE FLYING_TYPE
#define FARFETCHD_SECOND_TYPE NORMAL_TYPE

#define DODUO_ID 84
#define DODUO_NAME "Doduo"
#define DODUO_HEIGHT 1.4
#define DODUO_WEIGHT 39.2
#define DODUO_FIRST_TYPE FLYING_TYPE
#define DODUO_SECOND_TYPE NORMAL_TYPE

#define DODRIO_ID 85
#define DODRIO_NAME "Dodrio"
#define DODRIO_HEIGHT 1.8
#define DODRIO_WEIGHT 85.2
#define DODRIO_FIRST_TYPE FLYING_TYPE
#define DODRIO_SECOND_TYPE NORMAL_TYPE

#define SEEL_ID 86
#define SEEL_NAME "Seel"
#define SEEL_HEIGHT 1.1
#define SEEL_WEIGHT 90.0
#define SEEL_FIRST_TYPE WATER_TYPE
#define SEEL_SECOND_TYPE NONE_TYPE

#define DEWGONG_ID 87
#define DEWGONG_NAME "Dewgong"
#define DEWGONG_HEIGHT 1.7
#define DEWGONG_WEIGHT 120.0
#define DEWGONG_FIRST_TYPE ICE_TYPE
#define DEWGONG_SECOND_TYPE WATER_TYPE

#define GRIMER_ID 88
#define GRIMER_NAME "Grimer"
#define GRIMER_HEIGHT 0.9
#define GRIMER_WEIGHT 30.0
#define GRIMER_FIRST_TYPE POISON_TYPE
#define GRIMER_SECOND_TYPE NONE_TYPE

#define MUK_ID 89
#define MUK_NAME "Muk"
#define MUK_HEIGHT 1.2
#define MUK_WEIGHT 30.0
#define MUK_FIRST_TYPE POISON_TYPE
#define MUK_SECOND_TYPE NONE_TYPE

#define SHELLDER_ID 90
#define SHELLDER_NAME "Shellder"
#define SHELLDER_HEIGHT 0.3
#define SHELLDER_WEIGHT 4.0
#define SHELLDER_FIRST_TYPE WATER_TYPE
#define SHELLDER_SECOND_TYPE NONE_TYPE

#define CLOYSTER_ID 91
#define CLOYSTER_NAME "Cloyster"
#define CLOYSTER_HEIGHT 1.5
#define CLOYSTER_WEIGHT 132.5
#define CLOYSTER_FIRST_TYPE ICE_TYPE
#define CLOYSTER_SECOND_TYPE WATER_TYPE

#define GASTLY_ID 92
#define GASTLY_NAME "Gastly"
#define GASTLY_HEIGHT 1.3
#define GASTLY_WEIGHT 0.1
#define GASTLY_FIRST_TYPE POISON_TYPE
#define GASTLY_SECOND_TYPE GHOST_TYPE

#define HAUNTER_ID 93
#define HAUNTER_NAME "Haunter"
#define HAUNTER_HEIGHT 1.6
#define HAUNTER_WEIGHT 0.1
#define HAUNTER_FIRST_TYPE POISON_TYPE
#define HAUNTER_SECOND_TYPE GHOST_TYPE

#define GENGAR_ID 94
#define GENGAR_NAME "Gengar"
#define GENGAR_HEIGHT 1.5
#define GENGAR_WEIGHT 40.5
#define GENGAR_FIRST_TYPE POISON_TYPE
#define GENGAR_SECOND_TYPE GHOST_TYPE

#define ONIX_ID 95
#define ONIX_NAME "Onix"
#define ONIX_HEIGHT 8.8
#define ONIX_WEIGHT 210.0
#define ONIX_FIRST_TYPE GROUND_TYPE
#define ONIX_SECOND_TYPE ROCK_TYPE

#define DROWZEE_ID 96
#define DROWZEE_NAME "Drowzee"
#define DROWZEE_HEIGHT 1.0
#define DROWZEE_WEIGHT 32.4
#define DROWZEE_FIRST_TYPE PSYCHIC_TYPE
#define DROWZEE_SECOND_TYPE NONE_TYPE

#define HYPNO_ID 97
#define HYPNO_NAME "Hypno"
#define HYPNO_HEIGHT 1.6
#define HYPNO_WEIGHT 75.6
#define HYPNO_FIRST_TYPE PSYCHIC_TYPE
#define HYPNO_SECOND_TYPE NONE_TYPE

#define KRABBY_ID 98
#define KRABBY_NAME "Krabby"
#define KRABBY_HEIGHT 0.4
#define KRABBY_WEIGHT 6.5
#define KRABBY_FIRST_TYPE WATER_TYPE
#define KRABBY_SECOND_TYPE NONE_TYPE

#define KINGLER_ID 99
#define KINGLER_NAME "Kingler"
#define KINGLER_HEIGHT 1.3
#define KINGLER_WEIGHT 60.0
#define KINGLER_FIRST_TYPE WATER_TYPE
#define KINGLER_SECOND_TYPE NONE_TYPE

#define VOLTORB_ID 100
#define VOLTORB_NAME "Voltorb"
#define VOLTORB_HEIGHT 0.5
#define VOLTORB_WEIGHT 10.4
#define VOLTORB_FIRST_TYPE ELECTRIC_TYPE
#define VOLTORB_SECOND_TYPE NONE_TYPE

#define ELECTRODE_ID 101
#define ELECTRODE_NAME "Electrode"
#define ELECTRODE_HEIGHT 1.2
#define ELECTRODE_WEIGHT 66.6
#define ELECTRODE_FIRST_TYPE ELECTRIC_TYPE
#define ELECTRODE_SECOND_TYPE NONE_TYPE

#define EXEGGCUTE_ID 102
#define EXEGGCUTE_NAME "Exeggcute"
#define EXEGGCUTE_HEIGHT 0.4
#define EXEGGCUTE_WEIGHT 2.5
#define EXEGGCUTE_FIRST_TYPE PSYCHIC_TYPE
#define EXEGGCUTE_SECOND_TYPE GRASS_TYPE

#define EXEGGUTOR_ID 103
#define EXEGGUTOR_NAME "Exeggutor"
#define EXEGGUTOR_HEIGHT 2.0
#define EXEGGUTOR_WEIGHT 120.0
#define EXEGGUTOR_FIRST_TYPE PSYCHIC_TYPE
#define EXEGGUTOR_SECOND_TYPE GRASS_TYPE

#define CUBONE_ID 104
#define CUBONE_NAME "Cubone"
#define CUBONE_HEIGHT 0.4
#define CUBONE_WEIGHT 6.5
#define CUBONE_FIRST_TYPE GROUND_TYPE
#define CUBONE_SECOND_TYPE NONE_TYPE

#define MAROWAK_ID 105
#define MAROWAK_NAME "Marowak"
#define MAROWAK_HEIGHT 1.0
#define MAROWAK_WEIGHT 45.0
#define MAROWAK_FIRST_TYPE GROUND_TYPE
#define MAROWAK_SECOND_TYPE NONE_TYPE

#define HITMONLEE_ID 106
#define HITMONLEE_NAME "Hitmonlee"
#define HITMONLEE_HEIGHT 1.5
#define HITMONLEE_WEIGHT 49.8
#define HITMONLEE_FIRST_TYPE FIGHTING_TYPE
#define HITMONLEE_SECOND_TYPE NONE_TYPE

#define HITMONCHAN_ID 107
#define HITMONCHAN_NAME "Hitmonchan"
#define HITMONCHAN_HEIGHT 1.4
#define HITMONCHAN_WEIGHT 50.2
#define HITMONCHAN_FIRST_TYPE FIGHTING_TYPE
#define HITMONCHAN_SECOND_TYPE NONE_TYPE

#define LICKITUNG_ID 108
#define LICKITUNG_NAME "Lickitung"
#define LICKITUNG_HEIGHT 1.2
#define LICKITUNG_WEIGHT 65.5
#define LICKITUNG_FIRST_TYPE NORMAL_TYPE
#define LICKITUNG_SECOND_TYPE NONE_TYPE

#define KOFFING_ID 109
#define KOFFING_NAME "Koffing"
#define KOFFING_HEIGHT 0.6
#define KOFFING_WEIGHT 1.0
#define KOFFING_FIRST_TYPE POISON_TYPE
#define KOFFING_SECOND_TYPE NONE_TYPE

#define WEEZING_ID 110
#define WEEZING_NAME "Weezing"
#define WEEZING_HEIGHT 1.2
#define WEEZING_WEIGHT 9.5
#define WEEZING_FIRST_TYPE POISON_TYPE
#define WEEZING_SECOND_TYPE NONE_TYPE

#define RHYHORN_ID 111
#define RHYHORN_NAME "Rhyhorn"
#define RHYHORN_HEIGHT 1.0
#define RHYHORN_WEIGHT 115.0
#define RHYHORN_FIRST_TYPE ROCK_TYPE
#define RHYHORN_SECOND_TYPE GROUND_TYPE

#define RHYDON_ID 112
#define RHYDON_NAME "Rhydon"
#define RHYDON_HEIGHT 1.9
#define RHYDON_WEIGHT 120.0
#define RHYDON_FIRST_TYPE ROCK_TYPE
#define RHYDON_SECOND_TYPE GROUND_TYPE

#define CHANSEY_ID 113
#define CHANSEY_NAME "Chansey"
#define CHANSEY_HEIGHT 1.1
#define CHANSEY_WEIGHT 34.6
#define CHANSEY_FIRST_TYPE NORMAL_TYPE
#define CHANSEY_SECOND_TYPE NONE_TYPE

#define TANGELA_ID 114
#define TANGELA_NAME "Tangela"
#define TANGELA_HEIGHT 1.0
#define TANGELA_WEIGHT 35.0
#define TANGELA_FIRST_TYPE GRASS_TYPE
#define TANGELA_SECOND_TYPE NONE_TYPE

#define KANGASKHAN_ID 115
#define KANGASKHAN_NAME "Kangaskhan"
#define KANGASKHAN_HEIGHT 2.2
#define KANGASKHAN_WEIGHT 80.0
#define KANGASKHAN_FIRST_TYPE NORMAL_TYPE
#define KANGASKHAN_SECOND_TYPE NONE_TYPE

#define HORSEA_ID 116
#define HORSEA_NAME "Horsea"
#define HORSEA_HEIGHT 0.4
#define HORSEA_WEIGHT 8.0
#define HORSEA_FIRST_TYPE WATER_TYPE
#define HORSEA_SECOND_TYPE NONE_TYPE

#define SEADRA_ID 117
#define SEADRA_NAME "Seadra"
#define SEADRA_HEIGHT 1.2
#define SEADRA_WEIGHT 25.0
#define SEADRA_FIRST_TYPE WATER_TYPE
#define SEADRA_SECOND_TYPE NONE_TYPE

#define GOLDEEN_ID 118
#define GOLDEEN_NAME "Goldeen"
#define GOLDEEN_HEIGHT 0.6
#define GOLDEEN_WEIGHT 15.0
#define GOLDEEN_FIRST_TYPE WATER_TYPE
#define GOLDEEN_SECOND_TYPE NONE_TYPE

#define SEAKING_ID 119
#define SEAKING_NAME "Seaking"
#define SEAKING_HEIGHT 1.3
#define SEAKING_WEIGHT 39.0
#define SEAKING_FIRST_TYPE WATER_TYPE
#define SEAKING_SECOND_TYPE NONE_TYPE

#define STARYU_ID 120
#define STARYU_NAME "Staryu"
#define STARYU_HEIGHT 0.8
#define STARYU_WEIGHT 34.5
#define STARYU_FIRST_TYPE WATER_TYPE
#define STARYU_SECOND_TYPE NONE_TYPE

#define STARMIE_ID 121
#define STARMIE_NAME "Starmie"
#define STARMIE_HEIGHT 1.1
#define STARMIE_WEIGHT 80.0
#define STARMIE_FIRST_TYPE PSYCHIC_TYPE
#define STARMIE_SECOND_TYPE WATER_TYPE

#define MRMIME_ID 122
#define MRMIME_NAME "Mrmime"
#define MRMIME_HEIGHT 1.3
#define MRMIME_WEIGHT 54.5
#define MRMIME_FIRST_TYPE FAIRY_TYPE
#define MRMIME_SECOND_TYPE PSYCHIC_TYPE

#define SCYTHER_ID 123
#define SCYTHER_NAME "Scyther"
#define SCYTHER_HEIGHT 1.5
#define SCYTHER_WEIGHT 56.0
#define SCYTHER_FIRST_TYPE FLYING_TYPE
#define SCYTHER_SECOND_TYPE BUG_TYPE

#define JYNX_ID 124
#define JYNX_NAME "Jynx"
#define JYNX_HEIGHT 1.4
#define JYNX_WEIGHT 40.6
#define JYNX_FIRST_TYPE PSYCHIC_TYPE
#define JYNX_SECOND_TYPE ICE_TYPE

#define ELECTABUZZ_ID 125
#define ELECTABUZZ_NAME "Electabuzz"
#define ELECTABUZZ_HEIGHT 1.1
#define ELECTABUZZ_WEIGHT 30.0
#define ELECTABUZZ_FIRST_TYPE ELECTRIC_TYPE
#define ELECTABUZZ_SECOND_TYPE NONE_TYPE

#define MAGMAR_ID 126
#define MAGMAR_NAME "Magmar"
#define MAGMAR_HEIGHT 1.3
#define MAGMAR_WEIGHT 44.5
#define MAGMAR_FIRST_TYPE FIRE_TYPE
#define MAGMAR_SECOND_TYPE NONE_TYPE

#define PINSIR_ID 127
#define PINSIR_NAME "Pinsir"
#define PINSIR_HEIGHT 1.5
#define PINSIR_WEIGHT 55.0
#define PINSIR_FIRST_TYPE BUG_TYPE
#define PINSIR_SECOND_TYPE NONE_TYPE

#define TAUROS_ID 128
#define TAUROS_NAME "Tauros"
#define TAUROS_HEIGHT 1.4
#define TAUROS_WEIGHT 88.4
#define TAUROS_FIRST_TYPE NORMAL_TYPE
#define TAUROS_SECOND_TYPE NONE_TYPE

#define MAGIKARP_ID 129
#define MAGIKARP_NAME "Magikarp"
#define MAGIKARP_HEIGHT 0.9
#define MAGIKARP_WEIGHT 10.0
#define MAGIKARP_FIRST_TYPE WATER_TYPE
#define MAGIKARP_SECOND_TYPE NONE_TYPE

#define GYARADOS_ID 130
#define GYARADOS_NAME "Gyarados"
#define GYARADOS_HEIGHT 6.5
#define GYARADOS_WEIGHT 235.0
#define GYARADOS_FIRST_TYPE FLYING_TYPE
#define GYARADOS_SECOND_TYPE WATER_TYPE

#define LAPRAS_ID 131
#define LAPRAS_NAME "Lapras"
#define LAPRAS_HEIGHT 2.5
#define LAPRAS_WEIGHT 220.0
#define LAPRAS_FIRST_TYPE ICE_TYPE
#define LAPRAS_SECOND_TYPE WATER_TYPE

#define DITTO_ID 132
#define DITTO_NAME "Ditto"
#define DITTO_HEIGHT 0.3
#define DITTO_WEIGHT 4.0
#define DITTO_FIRST_TYPE NORMAL_TYPE
#define DITTO_SECOND_TYPE NONE_TYPE

#define EEVEE_ID 133
#define EEVEE_NAME "Eevee"
#define EEVEE_HEIGHT 0.3
#define EEVEE_WEIGHT 6.5
#define EEVEE_FIRST_TYPE NORMAL_TYPE
#define EEVEE_SECOND_TYPE NONE_TYPE

#define VAPOREON_ID 134
#define VAPOREON_NAME "Vaporeon"
#define VAPOREON_HEIGHT 1.0
#define VAPOREON_WEIGHT 29.0
#define VAPOREON_FIRST_TYPE WATER_TYPE
#define VAPOREON_SECOND_TYPE NONE_TYPE

#define JOLTEON_ID 135
#define JOLTEON_NAME "Jolteon"
#define JOLTEON_HEIGHT 0.8
#define JOLTEON_WEIGHT 24.5
#define JOLTEON_FIRST_TYPE ELECTRIC_TYPE
#define JOLTEON_SECOND_TYPE NONE_TYPE

#define FLAREON_ID 136
#define FLAREON_NAME "Flareon"
#define FLAREON_HEIGHT 0.9
#define FLAREON_WEIGHT 25.0
#define FLAREON_FIRST_TYPE FIRE_TYPE
#define FLAREON_SECOND_TYPE NONE_TYPE

#define PORYGON_ID 137
#define PORYGON_NAME "Porygon"
#define PORYGON_HEIGHT 0.8
#define PORYGON_WEIGHT 36.5
#define PORYGON_FIRST_TYPE NORMAL_TYPE
#define PORYGON_SECOND_TYPE NONE_TYPE

#define OMANYTE_ID 138
#define OMANYTE_NAME "Omanyte"
#define OMANYTE_HEIGHT 0.4
#define OMANYTE_WEIGHT 7.5
#define OMANYTE_FIRST_TYPE WATER_TYPE
#define OMANYTE_SECOND_TYPE ROCK_TYPE

#define OMASTAR_ID 139
#define OMASTAR_NAME "Omastar"
#define OMASTAR_HEIGHT 1.0
#define OMASTAR_WEIGHT 35.0
#define OMASTAR_FIRST_TYPE WATER_TYPE
#define OMASTAR_SECOND_TYPE ROCK_TYPE

#define KABUTO_ID 140
#define KABUTO_NAME "Kabuto"
#define KABUTO_HEIGHT 0.5
#define KABUTO_WEIGHT 11.5
#define KABUTO_FIRST_TYPE WATER_TYPE
#define KABUTO_SECOND_TYPE ROCK_TYPE

#define KABUTOPS_ID 141
#define KABUTOPS_NAME "Kabutops"
#define KABUTOPS_HEIGHT 1.3
#define KABUTOPS_WEIGHT 40.5
#define KABUTOPS_FIRST_TYPE WATER_TYPE
#define KABUTOPS_SECOND_TYPE ROCK_TYPE

#define AERODACTYL_ID 142
#define AERODACTYL_NAME "Aerodactyl"
#define AERODACTYL_HEIGHT 1.8
#define AERODACTYL_WEIGHT 59.0
#define AERODACTYL_FIRST_TYPE FLYING_TYPE
#define AERODACTYL_SECOND_TYPE ROCK_TYPE

#define SNORLAX_ID 143
#define SNORLAX_NAME "Snorlax"
#define SNORLAX_HEIGHT 2.1
#define SNORLAX_WEIGHT 460.0
#define SNORLAX_FIRST_TYPE NORMAL_TYPE
#define SNORLAX_SECOND_TYPE NONE_TYPE

#define ARTICUNO_ID 144
#define ARTICUNO_NAME "Articuno"
#define ARTICUNO_HEIGHT 1.7
#define ARTICUNO_WEIGHT 55.4
#define ARTICUNO_FIRST_TYPE FLYING_TYPE
#define ARTICUNO_SECOND_TYPE ICE_TYPE

#define ZAPDOS_ID 145
#define ZAPDOS_NAME "Zapdos"
#define ZAPDOS_HEIGHT 1.6
#define ZAPDOS_WEIGHT 52.6
#define ZAPDOS_FIRST_TYPE FLYING_TYPE
#define ZAPDOS_SECOND_TYPE ELECTRIC_TYPE

#define MOLTRES_ID 146
#define MOLTRES_NAME "Moltres"
#define MOLTRES_HEIGHT 2.0
#define MOLTRES_WEIGHT 60.0
#define MOLTRES_FIRST_TYPE FLYING_TYPE
#define MOLTRES_SECOND_TYPE FIRE_TYPE

#define DRATINI_ID 147
#define DRATINI_NAME "Dratini"
#define DRATINI_HEIGHT 1.8
#define DRATINI_WEIGHT 3.3
#define DRATINI_FIRST_TYPE DRAGON_TYPE
#define DRATINI_SECOND_TYPE NONE_TYPE

#define DRAGONAIR_ID 148
#define DRAGONAIR_NAME "Dragonair"
#define DRAGONAIR_HEIGHT 4.0
#define DRAGONAIR_WEIGHT 16.5
#define DRAGONAIR_FIRST_TYPE DRAGON_TYPE
#define DRAGONAIR_SECOND_TYPE NONE_TYPE

#define DRAGONITE_ID 149
#define DRAGONITE_NAME "Dragonite"
#define DRAGONITE_HEIGHT 2.2
#define DRAGONITE_WEIGHT 210.0
#define DRAGONITE_FIRST_TYPE FLYING_TYPE
#define DRAGONITE_SECOND_TYPE DRAGON_TYPE

#define MEWTWO_ID 150
#define MEWTWO_NAME "Mewtwo"
#define MEWTWO_HEIGHT 2.0
#define MEWTWO_WEIGHT 122.0
#define MEWTWO_FIRST_TYPE PSYCHIC_TYPE
#define MEWTWO_SECOND_TYPE NONE_TYPE

#define MEW_ID 151
#define MEW_NAME "Mew"
#define MEW_HEIGHT 0.4
#define MEW_WEIGHT 4.0
#define MEW_FIRST_TYPE PSYCHIC_TYPE
#define MEW_SECOND_TYPE NONE_TYPE

// Add your own prototypes here.

static void create_add_10_pokemon(Pokedex pokedex);
static void create_add_20_pokemon(Pokedex pokedex);
static void create_add_151_pokemon(Pokedex pokedex);

static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static Pokemon create_venusaur(void);
static Pokemon create_charmander(void);
static Pokemon create_charmeleon(void);
static Pokemon create_charizard(void);
static Pokemon create_squirtle(void);
static Pokemon create_wartortle(void);
static Pokemon create_blastoise(void);
static Pokemon create_caterpie(void);
static Pokemon create_metapod(void);
static Pokemon create_butterfree(void);
static Pokemon create_weedle(void);
static Pokemon create_kakuna(void);
static Pokemon create_beedrill(void);
static Pokemon create_pidgey(void);
static Pokemon create_pidgeotto(void);
static Pokemon create_pidgeot(void);
static Pokemon create_rattata(void);
static Pokemon create_raticate(void);
static Pokemon create_spearow(void);
static Pokemon create_fearow(void);
static Pokemon create_ekans(void);
static Pokemon create_arbok(void);
static Pokemon create_pikachu(void);
static Pokemon create_raichu(void);
static Pokemon create_sandshrew(void);
static Pokemon create_sandslash(void);
static Pokemon create_nidoranf(void);
static Pokemon create_nidorina(void);
static Pokemon create_nidoqueen(void);
static Pokemon create_nidoranm(void);
static Pokemon create_nidorino(void);
static Pokemon create_nidoking(void);
static Pokemon create_clefairy(void);
static Pokemon create_clefable(void);
static Pokemon create_vulpix(void);
static Pokemon create_ninetales(void);
static Pokemon create_jigglypuff(void);
static Pokemon create_wigglytuff(void);
static Pokemon create_zubat(void);
static Pokemon create_golbat(void);
static Pokemon create_oddish(void);
static Pokemon create_gloom(void);
static Pokemon create_vileplume(void);
static Pokemon create_paras(void);
static Pokemon create_parasect(void);
static Pokemon create_venonat(void);
static Pokemon create_venomoth(void);
static Pokemon create_diglett(void);
static Pokemon create_dugtrio(void);
static Pokemon create_meowth(void);
static Pokemon create_persian(void);
static Pokemon create_psyduck(void);
static Pokemon create_golduck(void);
static Pokemon create_mankey(void);
static Pokemon create_primeape(void);
static Pokemon create_growlithe(void);
static Pokemon create_arcanine(void);
static Pokemon create_poliwag(void);
static Pokemon create_poliwhirl(void);
static Pokemon create_poliwrath(void);
static Pokemon create_abra(void);
static Pokemon create_kadabra(void);
static Pokemon create_alakazam(void);
static Pokemon create_machop(void);
static Pokemon create_machoke(void);
static Pokemon create_machamp(void);
static Pokemon create_bellsprout(void);
static Pokemon create_weepinbell(void);
static Pokemon create_victreebel(void);
static Pokemon create_tentacool(void);
static Pokemon create_tentacruel(void);
static Pokemon create_geodude(void);
static Pokemon create_graveler(void);
static Pokemon create_golem(void);
static Pokemon create_ponyta(void);
static Pokemon create_rapidash(void);
static Pokemon create_slowpoke(void);
static Pokemon create_slowbro(void);
static Pokemon create_magnemite(void);
static Pokemon create_magneton(void);
static Pokemon create_farfetchd(void);
static Pokemon create_doduo(void);
static Pokemon create_dodrio(void);
static Pokemon create_seel(void);
static Pokemon create_dewgong(void);
static Pokemon create_grimer(void);
static Pokemon create_muk(void);
static Pokemon create_shellder(void);
static Pokemon create_cloyster(void);
static Pokemon create_gastly(void);
static Pokemon create_haunter(void);
static Pokemon create_gengar(void);
static Pokemon create_onix(void);
static Pokemon create_drowzee(void);
static Pokemon create_hypno(void);
static Pokemon create_krabby(void);
static Pokemon create_kingler(void);
static Pokemon create_voltorb(void);
static Pokemon create_electrode(void);
static Pokemon create_exeggcute(void);
static Pokemon create_exeggutor(void);
static Pokemon create_cubone(void);
static Pokemon create_marowak(void);
static Pokemon create_hitmonlee(void);
static Pokemon create_hitmonchan(void);
static Pokemon create_lickitung(void);
static Pokemon create_koffing(void);
static Pokemon create_weezing(void);
static Pokemon create_rhyhorn(void);
static Pokemon create_rhydon(void);
static Pokemon create_chansey(void);
static Pokemon create_tangela(void);
static Pokemon create_kangaskhan(void);
static Pokemon create_horsea(void);
static Pokemon create_seadra(void);
static Pokemon create_goldeen(void);
static Pokemon create_seaking(void);
static Pokemon create_staryu(void);
static Pokemon create_starmie(void);
static Pokemon create_mrmime(void);
static Pokemon create_scyther(void);
static Pokemon create_jynx(void);
static Pokemon create_electabuzz(void);
static Pokemon create_magmar(void);
static Pokemon create_pinsir(void);
static Pokemon create_tauros(void);
static Pokemon create_magikarp(void);
static Pokemon create_gyarados(void);
static Pokemon create_lapras(void);
static Pokemon create_ditto(void);
static Pokemon create_eevee(void);
static Pokemon create_vaporeon(void);
static Pokemon create_jolteon(void);
static Pokemon create_flareon(void);
static Pokemon create_porygon(void);
static Pokemon create_omanyte(void);
static Pokemon create_omastar(void);
static Pokemon create_kabuto(void);
static Pokemon create_kabutops(void);
static Pokemon create_aerodactyl(void);
static Pokemon create_snorlax(void);
static Pokemon create_articuno(void);
static Pokemon create_zapdos(void);
static Pokemon create_moltres(void);
static Pokemon create_dratini(void);
static Pokemon create_dragonair(void);
static Pokemon create_dragonite(void);
static Pokemon create_mewtwo(void);
static Pokemon create_mew(void);

// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void);
static void test_add_pokemon(void);
static void test_detail_pokemon(void);
static void test_get_current_pokemon(void);
static void test_find_current_pokemon(void);
static void test_print_pokemon(void);
static void test_next_pokemon(void);
static void test_prev_pokemon(void);
static void test_change_current_pokemon(void);
static void test_remove_pokemon(void);
static void test_destroy_pokedex(void);
static void test_go_exploring(void);
static void test_count_found_pokemon(void);
static void test_count_total_pokemon(void);
static void test_evolutions();
static void test_get_pokemon_of_type(void);
static void test_get_found_pokemon(void);
static void test_search_pokemon(void);
static void display_type(void);
// Helper functions for creating/comparing Pokemon.
static int same_pokemon(Pokemon A, Pokemon B);

int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");
    
      test_new_pokedex();
      test_add_pokemon();
      test_detail_pokemon();
      test_get_current_pokemon();
      test_find_current_pokemon();
      test_print_pokemon(); 
      test_next_pokemon();
      test_prev_pokemon();
      test_change_current_pokemon();
      test_remove_pokemon();
      test_destroy_pokedex();
      test_go_exploring();
      test_count_found_pokemon();
      test_count_total_pokemon();
      test_evolutions();
      test_get_pokemon_of_type();
      test_get_found_pokemon();
      test_search_pokemon();
      display_type();     
printf("\033[0;32m////////////////////////////////////////////////////////////////////////\n");
printf("//             WOOHOO ALL TESTS PASSED, I AM AWESOME                  //\n");
printf("////////////////////////////////////////////////////////////////////////\033[0m\n");

}


////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

static void test_new_pokedex(void) {
    printf("\n>>\033[0;36mTesting new_pokedex\033[0m\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex = new_pokedex();

    printf("    ... Checking that the returned Pokedex is not NULL\n");
    usleep(DELAY_1);
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);
    destroy_pokedex(pokedex);
    printf("\033[0;32m>> Passed new_pokedex tests!\033[0m;\n\n");
    usleep(DELAY_2);
}

static void test_add_pokemon(void) {
    printf("\n>> \033[0;36mTesting add_pokemon\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex = new_pokedex();
    printf("    ... Creating Bulbasaur\n");
    usleep(DELAY_1);
    Pokemon bulbasaur = create_bulbasaur();
    printf("    ... Adding Bulbasaur to the Pokedex\n");
    usleep(DELAY_1);
    add_pokemon(pokedex, bulbasaur);
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);
    usleep(DELAY_1);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex_10 = new_pokedex();
    printf("    ... Creating and Adding 10 pokemon\n");
    usleep(DELAY_1);
    create_add_10_pokemon(pokedex_10);
    printf("    ... Checking total number of pokemon\n");
    assert(count_total_pokemon(pokedex_10) == 10);    
    usleep(DELAY_1);
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex_10);
    usleep(DELAY_1);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex_20 = new_pokedex();
    printf("    ... Creating and Adding 20 pokemon\n");
    usleep(DELAY_1);
    create_add_20_pokemon(pokedex_20);
    printf("    ... Checking total number of pokemon\n");
    usleep(DELAY_1);
    assert(count_total_pokemon(pokedex_20) == 20);
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex_20);
    usleep(DELAY_1);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex_151 = new_pokedex();
    printf("    ... Creating and Adding 151 pokemon\n");
    usleep(DELAY_1);
    create_add_151_pokemon(pokedex_151);
    printf("    ... Checking total number of pokemon\n");
    usleep(DELAY_1);
    assert(count_total_pokemon(pokedex_151) == 151);    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex_151);
    usleep(DELAY_1);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    
    printf("\n\033[0;32m>> Passed add_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


// "Test detail pokemon checks the detail of the pokemon
static void test_detail_pokemon()  {
    printf("\n>>\033[0;36m Testing detail_pokemon\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    usleep(DELAY_1);

    printf("    ... Testing detail_pokemon function on an empty pokedex\n");
    usleep(DELAY_1);    
    char test_output_0 [10] = {0};
    char *correct_output_0 = "\0";
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_0);
    detail_pokemon(pokedex);
    freopen ("/dev/tty", "a", stdout);
    assert(test_output_0[0] == correct_output_0[0]);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Creating Bulbasaur\n");
    usleep(DELAY_1);
    Pokemon bulbasaur = create_bulbasaur();
    printf("    ... Adding Bulbasaur to the Pokedex\n");
    usleep(DELAY_1);
    add_pokemon(pokedex, bulbasaur);
    
    char test_output_1[256] = {0};
    char *correct_output_1 = "Id: 001\n"
                           "Name: *********\n"
                           "Height: --\n"
                           "Weight: --\n"
                           "Type: --\n";
                         
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_1);
    detail_pokemon(pokedex);
    freopen ("/dev/tty", "a", stdout);     
    printf("    ... Testing detail_pokemon function\n");
    usleep(DELAY_1);
    int len;
    for(len=0; correct_output_1[len] != '\0'; len++);
    for (int i = 0; i<len; i++)   {
        assert(test_output_1[i] == correct_output_1[i]);
    }   
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    find_current_pokemon(pokedex);
    char test_output_2[256] = {0};
    char *correct_output_2 = "Id: 001\n"
                      "Name: Bulbasaur\n"
                      "Height: 0.7m\n"
                      "Weight: 6.9kg\n"
                      "Type: Poison Grass\n";
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_2);
    detail_pokemon(pokedex);
    freopen ("/dev/tty", "a", stdout);
    for(len=0; correct_output_2[len] != '\0'; len++);
    for(int i = 0; i < len; i++)   {
        assert(test_output_2[i] == correct_output_2[i]);
    }
    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);    
    destroy_pokedex(pokedex);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed detail_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


// testing for get_current function:
static void test_get_current_pokemon()  {
    printf("\n>> \033[0;36mTesting get_current_pokemon\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex = new_pokedex();
    printf("    ... Checking that current pokemon is NULL\n");
    usleep(DELAY_1);
    assert(get_current_pokemon(pokedex) == NULL);    
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Testing get_current_pokemon function with four pokemon\n");
    usleep(DELAY_1);
    Pokemon charmander = create_charmander();
    Pokemon mew = create_mew();
    Pokemon squirtle = create_squirtle();
    Pokemon zapdos = create_zapdos();
    add_pokemon(pokedex, charmander);
    assert(same_pokemon(get_current_pokemon(pokedex), charmander));
    add_pokemon(pokedex, mew);
    next_pokemon(pokedex);   
    assert(same_pokemon(get_current_pokemon(pokedex), mew));
    add_pokemon(pokedex, squirtle);
    next_pokemon(pokedex);
    assert(same_pokemon(get_current_pokemon(pokedex), squirtle));
    add_pokemon(pokedex, zapdos);
    next_pokemon(pokedex);
    assert(same_pokemon(get_current_pokemon(pokedex), zapdos));
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);
    destroy_pokedex(pokedex);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed get_current_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


// testing for find_current pokemon
static void test_find_current_pokemon()  {
    printf("\n>> \033[0;36mTesting find_current_pokemon function\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    usleep(DELAY_1);
    printf("    ... Creating and Adding 10 pokemon\n");
    usleep(DELAY_1);
    create_add_10_pokemon(pokedex);

    find_current_pokemon(pokedex);
    printf("    ... Setting pokemon 1 to be found\n");
    usleep(DELAY_1);
    assert(count_found_pokemon(pokedex) == 1);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    change_current_pokemon(pokedex, 6);
    assert(count_found_pokemon(pokedex) == 1);
    find_current_pokemon(pokedex);
    printf("    ... Setting pokemon 6 to be found\n");
    usleep(DELAY_1);
    assert(count_found_pokemon(pokedex) == 2);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    change_current_pokemon(pokedex, 10);
    assert(count_found_pokemon(pokedex) == 2);
    find_current_pokemon(pokedex);
    printf("    ... Setting pokemon 10 to be found\n");
    usleep(DELAY_1);
    assert(count_found_pokemon(pokedex) == 3);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    change_current_pokemon(pokedex, 4);
    assert(count_found_pokemon(pokedex) == 3);
    find_current_pokemon(pokedex);
    printf("    ... Setting pokemon 4 to be found\n");
    usleep(DELAY_1);
    assert(count_found_pokemon(pokedex) == 4);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    change_current_pokemon(pokedex, 6);
    assert(count_found_pokemon(pokedex) == 4);
    find_current_pokemon(pokedex);
    printf("    ... Setting pokemon 6 to be found again\n");
    usleep(DELAY_1);
    assert(count_found_pokemon(pokedex) == 4);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    change_current_pokemon(pokedex, 2);
    assert(count_found_pokemon(pokedex) == 4);
    
    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);    
    destroy_pokedex(pokedex);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed find_current_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


// testing for print_pokemon function:
static void test_print_pokemon()  {
    printf("\n>> \033[0;36mTesting print_pokemon function\033[0m;\n");
    usleep(DELAY_1);  
    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex = new_pokedex();
    printf("    ... Creating Bulbasaur\n");
    usleep(DELAY_1);
    Pokemon bulbasaur = create_bulbasaur();
    
    printf("    ... Adding Bulbasaur to the Pokedex\n");
    usleep(DELAY_1);
    add_pokemon(pokedex, bulbasaur);
   
    // testing one pokemon when not found    
    printf("    ... Testing print_pokemon function with 1 pokemon not found\n");
    usleep(DELAY_1);
    char test_output_1[256] = {0};
    char *correct_output_1 = "--> #001: *********\n";
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_1);
    print_pokemon(pokedex);
    freopen ("/dev/tty", "a", stdout);
    int len;
    for(len=0; correct_output_1[len] != '\0'; len++);
    for (int i = 0; i < len; i++) {
        assert(test_output_1[i] == correct_output_1[i]); 
    }
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    // testing one pokemon when found
    printf("    ... Testing print_pokemon function with 1 pokemon found\n");
    usleep(DELAY_1);
    find_current_pokemon(pokedex);
    char test_output_2[256] = {0};
    char *correct_output_2 = "--> #001: Bulbasaur\n";
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_2);
    print_pokemon(pokedex);
    freopen ("/dev/tty", "a", stdout);
    for(len=0; correct_output_2[len] != '\0'; len++);    
    for(int i = 0; i < len; i++)   {
        assert(test_output_2[i] == correct_output_2[i]);
    }
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    destroy_pokedex(pokedex);

    printf("    ... Testing with 10 pokemon\n");
    usleep(DELAY_1);
    Pokedex pokedex_10 = new_pokedex();
    printf("    ... Creating and Adding 10 pokemon\n");
    usleep(DELAY_1);
    create_add_10_pokemon(pokedex_10);
    printf("    ... Setting 3 pokemon to found\n");
    usleep(DELAY_1);
    find_current_pokemon(pokedex_10);
    change_current_pokemon(pokedex_10, 4);
    find_current_pokemon(pokedex_10);
    change_current_pokemon(pokedex_10, 6);
    find_current_pokemon(pokedex_10);

    printf("    ... Testing print_pokemon function with 10 pokemon\n");
    usleep(DELAY_1);    
    char test_output_3[1024] = {0};
    char *correct_output_3 =  "    #001: Bulbasaur\n" 
                              "    #002: *******\n"
                              "    #003: ********\n"
                              "    #004: Charmander\n"
                              "    #005: **********\n"
                              "--> #006: Charizard\n"
                              "    #007: ********\n"
                              "    #008: *********\n"
                              "    #009: *********\n"
                              "    #010: ********\n";
                                
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_3);
    print_pokemon(pokedex_10);
    freopen ("/dev/tty", "a", stdout);
    for(len=0; correct_output_3[len] != '\0'; len++);
    for (int i = 0; i < len; i++) {
        assert(test_output_3[i] == correct_output_3[i]);
    }    
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);
    destroy_pokedex(pokedex_10);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("\033[0;32m>> Passed print_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void test_next_pokemon()  {
    printf("\n>> \033[0;36mTesting next_pokemon function\033[0m\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex = new_pokedex();
    printf("    ... Creating and Adding 20 pokemon\n");
    usleep(DELAY_1);
    create_add_20_pokemon(pokedex);
    printf("    ... Traversing through 20 pokemon using the next pokemon function\n");
    usleep(DELAY_1);
    for (int i = 1; i < 21; i++) {
        assert(pokemon_id(get_current_pokemon(pokedex)) == i);
        next_pokemon(pokedex);
    }
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Checking next pokemon for last pokemon\n");
    usleep(DELAY_1);
    next_pokemon(pokedex);
    assert(pokemon_id(get_current_pokemon(pokedex)) == 20);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);
    destroy_pokedex(pokedex);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed next_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void test_prev_pokemon()  {
    printf("\n>> \033[0;36mTesting prev_pokemon function\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex = new_pokedex();
    printf("    ... Creating and Adding 20 pokemon\n");
    usleep(DELAY_1);
    create_add_20_pokemon(pokedex);
    change_current_pokemon(pokedex, 20);
    printf("    ... Traversing through 20 pokemon using the previous pokemon function\n");
    usleep(DELAY_1);
    for (int i = 20; i > 0; i--) {
        assert(pokemon_id(get_current_pokemon(pokedex)) == i);
        prev_pokemon(pokedex);
    }
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Checking the previous pokemon for first pokemon\n");
    usleep(DELAY_1);
    prev_pokemon(pokedex);
    assert(pokemon_id(get_current_pokemon(pokedex)) == 1);
    usleep(DELAY_1);
    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);
    destroy_pokedex(pokedex);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed prev_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void test_change_current_pokemon()  {
    printf("\n>> \033[0;36mTesting change_current_pokemon\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex_20 = new_pokedex();
    printf("    ... Creating and Adding 20 pokemon\n");
    usleep(DELAY_1);
    create_add_20_pokemon(pokedex_20);

    printf("    ... changing id to non-existent pokemon\n");
    usleep(DELAY_1);
    change_current_pokemon(pokedex_20, 42);
    assert(pokemon_id(get_current_pokemon(pokedex_20)) == 1);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);  

    printf("    ... Changing id to existent pokemon\n");
    usleep(DELAY_1);
    change_current_pokemon(pokedex_20, 7);
    assert(pokemon_id(get_current_pokemon(pokedex_20)) == 7);
    change_current_pokemon(pokedex_20, 18);
    assert(pokemon_id(get_current_pokemon(pokedex_20)) == 18);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Changing back to non-existent pokemon\n");
    usleep(DELAY_1);
    change_current_pokemon(pokedex_20, 35);
    assert(pokemon_id(get_current_pokemon(pokedex_20)) == 18);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);
    destroy_pokedex(pokedex_20);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed change_current_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void test_remove_pokemon()  {
    printf("\n>> \033[;36mTesting remove_pokemon\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex = new_pokedex();
    printf("    ... Creating and Adding 10 pokemon\n");
    usleep(DELAY_1);
    create_add_10_pokemon(pokedex);
    printf("    ... Removing first pokemon and checking that the current pokemon is the next\n");
    usleep(DELAY_1);
    remove_pokemon(pokedex);
    assert(pokemon_id(get_current_pokemon(pokedex)) == 2);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Removing a pokemon in the middle of the list and checking that the current pokemon is the next\n");
    usleep(DELAY_1);
    change_current_pokemon(pokedex, 5);
    remove_pokemon(pokedex);
    assert(pokemon_id(get_current_pokemon(pokedex)) == 6);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Removing a pokemon in the end of the list and checking that the current pokemon is the previous\n");
    usleep(DELAY_1);
    change_current_pokemon(pokedex, 10); 
    remove_pokemon(pokedex);
    assert(pokemon_id(get_current_pokemon(pokedex)) == 9);

    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);
    destroy_pokedex(pokedex);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed remove_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void test_destroy_pokedex()  {
    printf("\n>> \033[;36mTesting destroy_pokedex\033[0m;\n"); 
    usleep(DELAY_1);
    printf("    ... Testing destroy function\n");
    usleep(DELAY_1);
    printf("    ... This function has already been tested\n");
    printf("\033[0;32m   >> Passed destroy_pokedex tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void test_go_exploring()  {
    printf("\n>> \033[;36mTesting go_exploring\033[0m;\n");
    usleep(DELAY_1);
    printf("\033[;31m   WARNING: testing may fail on different operating systems due to the random number generator\033[0m; \n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex = new_pokedex();
    printf("    ... Creating and Adding 151 pokemon\n");
    usleep(DELAY_1);
    create_add_151_pokemon(pokedex);
    go_exploring(pokedex, 42, 151, 100);
    
    char test_output[4096] = {0};
    char *correct_output = "--> #077: Ponyta\n"
                           "    #041: Zubat\n"
                           "    #001: *********\n"
                           "    #011: *******\n"
                           "    #023: Ekans\n"
                           "    #052: ******\n"
                           "    #078: ********\n"
                           "    #130: ********\n"
                           "    #031: *********\n"
                           "    #110: Weezing\n"
                           "    #027: *********\n"
                           "    #111: *******\n"
                           "    #148: Dragonair\n"
                           "    #055: Golduck\n"
                           "    #101: Electrode\n"
                           "    #064: Kadabra\n"
                           "    #003: Venusaur\n"
                           "    #076: *****\n"
                           "    #151: ***\n"
                           "    #074: Geodude\n"
                           "    #147: *******\n"
                           "    #106: *********\n"
                           "    #032: ********\n"
                           "    #053: Persian\n"
                           "    #134: ********\n"
                           "    #093: *******\n"
                           "    #008: *********\n"
                           "    #150: ******\n"
                           "    #045: Vileplume\n"
                           "    #050: Diglett\n"
                           "    #069: Bellsprout\n"
                           "    #139: *******\n"
                           "    #131: ******\n"
                           "    #146: *******\n"
                           "    #098: Krabby\n"
                           "    #037: Vulpix\n"
                           "    #025: *******\n"
                           "    #123: *******\n"
                           "    #016: ******\n"
                           "    #081: Magnemite\n"
                           "    #090: Shellder\n"
                           "    #122: ******\n"
                           "    #043: Oddish\n"
                           "    #028: *********\n"
                           "    #068: *******\n"
                           "    #005: **********\n"
                           "    #102: Exeggcute\n"
                           "    #109: *******\n"
                           "    #135: Jolteon\n"
                           "    #082: Magneton\n"
                           "    #116: Horsea\n"
                           "    #034: Nidoking\n"
                           "    #015: Beedrill\n"
                           "    #033: Nidorino\n"
                           "    #142: **********\n"
                           "    #092: Gastly\n"
                           "    #086: Seel\n"
                           "    #024: Arbok\n"
                           "    #087: *******\n"
                           "    #091: Cloyster\n"
                           "    #128: ******\n"
                           "    #042: Golbat\n"
                           "    #100: Voltorb\n"
                           "    #114: *******\n"
                           "    #085: Dodrio\n"
                           "    #002: *******\n"
                           "    #006: Charizard\n"
                           "    #143: Snorlax\n"
                           "    #017: *********\n"
                           "    #126: Magmar\n"
                           "    #149: Dragonite\n"
                           "    #049: Venomoth\n"
                           "    #009: Blastoise\n"
                           "    #063: ****\n"
                           "    #080: *******\n"
                           "    #029: Nidoranf\n"
                           "    #145: Zapdos\n"
                           "    #044: *****\n"
                           "    #095: ****\n"
                           "    #013: ******\n"
                           "    #075: Graveler\n"
                           "    #038: Ninetales\n"
                           "    #010: Caterpie\n"
                           "    #057: ********\n"
                           "    #112: ******\n"
                           "    #132: Ditto\n"
                           "    #125: Electabuzz\n"
                           "    #039: Jigglypuff\n"
                           "    #061: *********\n"
                           "    #120: Staryu\n"
                           "    #066: Machop\n"
                           "    #127: ******\n"
                           "    #067: *******\n"
                           "    #046: Paras\n"
                           "    #133: Eevee\n"
                           "    #140: Kabuto\n"
                           "    #144: Articuno\n"
                           "    #054: *******\n"
                           "    #021: Spearow\n"
                           "    #117: Seadra\n"
                           "    #089: Muk\n"
                           "    #072: Tentacool\n"
                           "    #047: ********\n"
                           "    #030: ********\n"
                           "    #026: Raichu\n"
                           "    #088: ******\n"
                           "    #071: **********\n"
                           "    #065: Alakazam\n"
                           "    #107: **********\n"
                           "    #105: *******\n"
                           "    #129: ********\n"
                           "    #137: *******\n"
                           "    #012: Butterfree\n"
                           "    #051: Dugtrio\n"
                           "    #084: *****\n"
                           "    #113: Chansey\n"
                           "    #040: **********\n"
                           "    #118: Goldeen\n"
                           "    #119: *******\n"
                           "    #096: *******\n"
                           "    #014: ******\n"
                           "    #136: *******\n"
                           "    #079: ********\n"
                           "    #062: Poliwrath\n"
                           "    #083: *********\n"
                           "    #048: *******\n"
                           "    #108: Lickitung\n"
                           "    #060: Poliwag\n"
                           "    #138: Omanyte\n"
                           "    #035: ********\n"
                           "    #073: **********\n"
                           "    #099: *******\n"
                           "    #104: Cubone\n"
                           "    #121: *******\n"
                           "    #097: *****\n"
                           "    #141: Kabutops\n"
                           "    #020: ********\n"
                           "    #058: *********\n"
                           "    #022: Fearow\n"
                           "    #070: Weepinbell\n"
                           "    #004: **********\n"
                           "    #036: ********\n"
                           "    #124: Jynx\n"
                           "    #094: ******\n"
                           "    #007: ********\n"
                           "    #018: Pidgeot\n"
                           "    #059: ********\n"
                           "    #103: *********\n"
                           "    #115: **********\n"
                           "    #019: Rattata\n"
                           "    #056: Mankey\n";  
                            
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output);
    print_pokemon(pokedex);
    freopen ("/dev/tty", "a", stdout);
    printf("    ... Testing go_exploring and its print_pokemon function\n");
    usleep(DELAY_1);
    int len;
    for( len=0; correct_output[len] != '\0'; len++);
    for (int i = 0; i < len ; i++) {
        assert(test_output[i] == correct_output[i]);
    }
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);
    destroy_pokedex(pokedex);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed go_exploring tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void test_count_found_pokemon()  {
    printf("\n>>  \033[;36mTesting count_found_pokemon\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating empty pokedex and checking how many are found\n");
    usleep(DELAY_1);
    Pokedex pokedex = new_pokedex();
    assert(count_found_pokemon(pokedex) == 0);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Creating and Adding 151 pokemon\n");
    usleep(DELAY_1);
    create_add_151_pokemon(pokedex);
    go_exploring(pokedex, 42, 151, 100);
    printf("    ... Went exploring and checking how many pokemon were found\n");
    usleep(DELAY_1);
    assert(count_found_pokemon(pokedex) == 75);
    destroy_pokedex(pokedex);
    usleep(DELAY_1);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed count_found_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void test_count_total_pokemon()  {
    printf("\n>>  \033[;36mTesting count_total_pokemon\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex = new_pokedex();
    printf("    ... Testing count_total_pokemon function on empty pokedex\n");
    usleep(DELAY_1);
    assert(count_total_pokemon(pokedex) == 0);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Creating a new pokedex with 151 random pokemon\n");
    usleep(DELAY_1);
    Pokedex pokedex_151 = new_pokedex();
    create_add_151_pokemon(pokedex_151);
    change_current_pokemon(pokedex_151, 50);
    remove_pokemon(pokedex_151);
    change_current_pokemon(pokedex_151, 39);
    remove_pokemon(pokedex_151);
    change_current_pokemon(pokedex_151, 83);
    remove_pokemon(pokedex_151);
    printf("    ... Removed 3 pokemon and checking total pokemon in pokedex\n");
    usleep(DELAY_1);
    assert(count_total_pokemon(pokedex_151) == 148);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);
    destroy_pokedex(pokedex);
    destroy_pokedex(pokedex_151);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed count_total_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}

static void test_evolutions()  {
    printf("\n>> \033[;36mTesting add_pokemon_evolution function\033[0m;\n");
    printf(">> \033[;36mTesting show_evolutions function\033[0m;\n");
    printf(">> \033[;36mTesting get_evolutions function\033[0m;\n");

    printf("     ... Creating a new Pokedex\n");
    usleep(DELAY_1);
    Pokedex pokedex_10 = new_pokedex();
    printf("     ... Checking show_evolution function on empty pokedex\n");
    char test_output_0 [10] = {0};
    char *correct_output_0 = "\0";

    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_0);
    show_evolutions(pokedex_10);
    freopen ("/dev/tty", "a", stdout);
    assert(test_output_0[0] == correct_output_0[0]);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);   
 
    printf("    ... Creating and Adding 10 pokemon\n");
    usleep(DELAY_1);
    create_add_10_pokemon(pokedex_10);
    
    printf("    ... Adding pokemon evolution 005 to 006 - both not found\n");
    usleep(DELAY_1);
    change_current_pokemon(pokedex_10, 5);
    add_pokemon_evolution(pokedex_10, 005, 006);
    char test_output[256] = {0};
    char *correct_output = "#005 ???? [????] --> #006 ???? [????]\n"; 
    
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output);
    show_evolutions(pokedex_10);
    freopen ("/dev/tty", "a", stdout);
    int len;
    for(len=0; correct_output[len] != '\0'; len++);
    for (int i = 0; i < len; i++) {
        assert(test_output[i] == correct_output[i]);
    }
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("    ... Marking one pokemon as found and checking show_evolution\n");
    usleep(DELAY_1);
    find_current_pokemon(pokedex_10);
    char test_output_1 [256] = {0};
    char *correct_output_1 = "#005 Charmeleon [Fire] --> #006 ???? [????]\n"; 

    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_1);
    show_evolutions(pokedex_10);
    freopen ("/dev/tty", "a", stdout);
    for(len=0; correct_output_1[len] != '\0'; len++);
    for (int i = 0; i < len; i++) {
        assert(test_output_1[i] == correct_output_1[i]);
    }
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("    ... Marking both pokemon as found and checking show_evolution\n");
    usleep(DELAY_1);
    change_current_pokemon(pokedex_10, 6);
    find_current_pokemon(pokedex_10);
    change_current_pokemon(pokedex_10, 5);
    char test_output_2 [256] = {0}; 
    char *correct_output_2 = "#005 Charmeleon [Fire] --> #006 Charizard [Flying Fire]\n"; 

    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_2);
    show_evolutions(pokedex_10);
    freopen ("/dev/tty", "a", stdout);
    for(len=0; correct_output_2[len] != '\0'; len++);
    for (int i = 0; i < len; i++) {
        assert(test_output_2[i] == correct_output_2[i]);
    }
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("    ... Checking next evolution for pokemon with no next evolution\n");
    change_current_pokemon(pokedex_10, 6);
    usleep(DELAY_1);
    assert(get_next_evolution(pokedex_10) == DOES_NOT_EVOLVE);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("    ... Destroying the Pokedex\n");
    usleep(DELAY_1);
    destroy_pokedex(pokedex_10);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed all evolution function tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void test_get_pokemon_of_type()  {
    printf("\n>>  \033[;36mTesting get_pokemon_of_type\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex_151 = new_pokedex();
    usleep(DELAY_1);
    printf("    ... Testing get_pokemon_of_type_function with no pokemon in the pokedex\n");
    usleep(DELAY_1);
    char test_output [10] = {0};
    char *correct_output = "\0";

    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output);
    Pokedex fire_type_pokedex = get_pokemon_of_type(pokedex_151, FIRE_TYPE);
    print_pokemon(fire_type_pokedex);
    freopen ("/dev/tty", "a", stdout);
    assert(test_output[0] == correct_output[0]);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("    ... Creating and adding 151 pokemon to the pokedex\n");
    usleep(DELAY_1);
    create_add_151_pokemon(pokedex_151);
    printf("    ... Testing get_pokemon_of_type with 151 pokemon in pokedex - all not found\n"); 
    usleep(DELAY_1);

    char test_output_1 [10] = {0}; 
    char *correct_output_1 = "\0";

    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_1);
    Pokedex fire_type_pokedex_1 = get_pokemon_of_type(pokedex_151, FIRE_TYPE);
    print_pokemon(fire_type_pokedex_1);
    freopen ("/dev/tty", "a", stdout);
    assert(test_output_1[0] == correct_output_1[0]); 
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
 
    printf("    ... Going on a random walk and finding 75 pokemon\n");
    usleep(DELAY_1);
    go_exploring(pokedex_151, 42, 151, 100);
    Pokedex fire_type_pokedex_2 = get_pokemon_of_type(pokedex_151, FIRE_TYPE);
    
    char test_output_2[256] = {0};
    char *correct_output_2 = "--> #077: Ponyta\n"
                             "    #037: Vulpix\n"
                             "    #006: Charizard\n"
                             "    #126: Magmar\n"
                             "    #038: Ninetales\n";
   
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_2);
    print_pokemon(fire_type_pokedex_2);
    freopen ("/dev/tty", "a", stdout);
    printf("    ... Testing get_pokemon_of_type function\n");
    usleep(DELAY_1);
    int len;
    for(len=0; correct_output_2[len] != '\0'; len++);
    for (int i = 0; i < len; i++) {
        assert(test_output_2[i] == correct_output_2[i]);
    }
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("    ... Destroying the Pokedexes\n");
    usleep(DELAY_1);
    destroy_pokedex(fire_type_pokedex);
    destroy_pokedex(fire_type_pokedex_1);
    destroy_pokedex(fire_type_pokedex_2);
    destroy_pokedex(pokedex_151);
    usleep(DELAY_1);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);
    printf("\033[0;32m>> Passed get_pokemon_of_type tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void test_get_found_pokemon(void) {
 
    printf("\n>>  \033[;36mTesting get_found_pokemon\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex_151 = new_pokedex();
    usleep(DELAY_1);
    printf("    ... Creating and Adding 151 pokemon\n");
    usleep(DELAY_1);
    create_add_151_pokemon(pokedex_151);
    printf("    ... Going exploring and finding 75 pokemon\n");
    usleep(DELAY_1);
    go_exploring(pokedex_151, 42, 151, 100);
    Pokedex found_pokedex = get_found_pokemon(pokedex_151);
    char test_output[4096] = {0};
    char *correct_output = "--> #003: Venusaur\n"
                           "    #006: Charizard\n"
                           "    #009: Blastoise\n"
                           "    #010: Caterpie\n"
                           "    #012: Butterfree\n"
                           "    #015: Beedrill\n"
                           "    #018: Pidgeot\n"
                           "    #019: Rattata\n"
                           "    #021: Spearow\n"
                           "    #022: Fearow\n"
                           "    #023: Ekans\n"
                           "    #024: Arbok\n"
                           "    #026: Raichu\n"
                           "    #029: Nidoranf\n"
                           "    #033: Nidorino\n"
                           "    #034: Nidoking\n"
                           "    #037: Vulpix\n"
                           "    #038: Ninetales\n"
                           "    #039: Jigglypuff\n"
                           "    #041: Zubat\n"
                           "    #042: Golbat\n"
                           "    #043: Oddish\n"
                           "    #045: Vileplume\n"
                           "    #046: Paras\n"
                           "    #049: Venomoth\n"
                           "    #050: Diglett\n"
                           "    #051: Dugtrio\n"
                           "    #053: Persian\n"
                           "    #055: Golduck\n"
                           "    #056: Mankey\n"
                           "    #060: Poliwag\n"
                           "    #062: Poliwrath\n"
                           "    #064: Kadabra\n"
                           "    #065: Alakazam\n"
                           "    #066: Machop\n"
                           "    #069: Bellsprout\n"
                           "    #070: Weepinbell\n"
                           "    #072: Tentacool\n"
                           "    #074: Geodude\n"
                           "    #075: Graveler\n"
                           "    #077: Ponyta\n"
                           "    #081: Magnemite\n"
                           "    #082: Magneton\n"
                           "    #085: Dodrio\n"
                           "    #086: Seel\n"
                           "    #089: Muk\n"
                           "    #090: Shellder\n"
                           "    #091: Cloyster\n"
                           "    #092: Gastly\n"
                           "    #098: Krabby\n"
                           "    #100: Voltorb\n"
                           "    #101: Electrode\n"
                           "    #102: Exeggcute\n"
                           "    #104: Cubone\n"
                           "    #108: Lickitung\n"
                           "    #110: Weezing\n"
                           "    #113: Chansey\n"
                           "    #116: Horsea\n"
                           "    #117: Seadra\n"
                           "    #118: Goldeen\n"
                           "    #120: Staryu\n"
                           "    #124: Jynx\n"
                           "    #125: Electabuzz\n"
                           "    #126: Magmar\n"
                           "    #132: Ditto\n"
                           "    #133: Eevee\n"
                           "    #135: Jolteon\n"
                           "    #138: Omanyte\n"
                           "    #140: Kabuto\n"
                           "    #141: Kabutops\n"
                           "    #143: Snorlax\n"
                           "    #144: Articuno\n"
                           "    #145: Zapdos\n"
                           "    #148: Dragonair\n"
                           "    #149: Dragonite\n";
    
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output);
    print_pokemon(found_pokedex);
    freopen ("/dev/tty", "a", stdout);
    printf("    ... Testing get_found_pokemon function\n");
    usleep(DELAY_1);
    int len;
    for(len=0; correct_output[len] != '\0'; len++);
    for (int i = 0; i < len; i++) {
        assert(test_output[i] == correct_output[i]);
    } 


    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex_151);
    destroy_pokedex(found_pokedex);
    usleep(DELAY_1);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed get_found_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}



static void test_search_pokemon()  {

    char text[] = "Ar";
    printf("\n>>  \033[;36mTesting search_pokemon\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex_151 = new_pokedex();
    usleep(DELAY_1);
    printf("    ... Creating and adding 151 pokemon to the pokedex\n");
    create_add_151_pokemon(pokedex_151);
    usleep(DELAY_1);
    printf("    ... Testing search_pokemon function on pokedex with no found pokemon\n");
    usleep(DELAY_1);
    char test_output_0 [10] = {0};
    char *correct_output_0 = "\0";

    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output_0);
    Pokedex search_pokedex_0 = search_pokemon(pokedex_151, text);
    print_pokemon(search_pokedex_0);
    freopen ("/dev/tty", "a", stdout);
    assert(test_output_0[0] == correct_output_0[0]);    
    printf("\033[0;32m passed \033[0m\n");    
    usleep(DELAY_2);

    printf("    ... going on a random walk and finding 75 pokemon\n");
    usleep(DELAY_1);
    go_exploring(pokedex_151, 42, 151, 100);
    Pokedex search_pokedex = search_pokemon(pokedex_151, text);
   
    char test_output[256] = {0};
    char *correct_output = "--> #024: Arbok\n"
                           "    #006: Charizard\n"
                           "    #126: Magmar\n"
                           "    #120: Staryu\n"
                           "    #046: Paras\n"
                           "    #144: Articuno\n"
                           "    #021: Spearow\n"
                           "    #022: Fearow\n";

    freopen("/dev/null", "a", stdout);
    setbuf(stdout, test_output);
    print_pokemon(search_pokedex);
    freopen ("/dev/tty", "a", stdout);
    printf("    ... Testing search_pokemon function\n");
    usleep(DELAY_1);
    int len;
    for(len=0; correct_output[len] != '\0'; len++);
    for (int i = 0; i < len; i++) {
        assert(test_output[i] == correct_output[i]);
    }

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex_151);
    destroy_pokedex(search_pokedex_0);
    destroy_pokedex(search_pokedex);
    usleep(DELAY_1);
    printf("\033[0;32m passed \033[0m\n");
    usleep(DELAY_2);

    printf("\033[0;32m>> Passed search_pokemon tests!\033[0m;\n");
    usleep(DELAY_2);
}


static void display_type() {

    printf("\n>>  \033[;36mDisplaying types of pokemon in 151 pokedex\033[0m;\n");
    usleep(DELAY_1);
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex_151 = new_pokedex();
    usleep(DELAY_1);
    printf("    ... Creating and adding 151 pokemon to the pokedex\n");
    create_add_151_pokemon(pokedex_151);    
    usleep(DELAY_1);
    // Finding all pokemon
    for (int i = 0; i < 152; i++) {
        find_current_pokemon(pokedex_151);
        next_pokemon(pokedex_151);
    }
             
    Pokedex p1 = get_pokemon_of_type(pokedex_151, FIRE_TYPE);
    Pokedex p2 = get_pokemon_of_type(pokedex_151, WATER_TYPE);
    Pokedex p3 = get_pokemon_of_type(pokedex_151, GRASS_TYPE);
    Pokedex p4 = get_pokemon_of_type(pokedex_151, GROUND_TYPE);
    
    Pokedex fire_pokedex = get_found_pokemon(p1);
    Pokedex water_pokedex = get_found_pokemon(p2);
    Pokedex grass_pokedex = get_found_pokemon(p3);
    Pokedex ground_pokedex = get_found_pokemon(p4);
    
    destroy_pokedex(p1);
    destroy_pokedex(p2);
    destroy_pokedex(p3);
    destroy_pokedex(p4);

    sleep(DELAY_3);
    printf("\n\n\n");
    printf(" Displaying the four main types of pokemon\n");
    sleep(DELAY_4);
    printf("\033[0;31mFIRE TYPE\n");
    sleep(DELAY_3);
    print_pokemon(fire_pokedex);
    sleep(DELAY_4);
    printf("\033[0m\n");
    printf("\033[0;36mWATER TYPE\n");
    sleep(DELAY_3);
    print_pokemon(water_pokedex);
    sleep(DELAY_4);
    printf("\033[0m\n");
    printf("\033[0;32mGRASS TYPE\n");
    sleep(DELAY_3);
    print_pokemon(grass_pokedex);
    sleep(DELAY_4);
    printf("\033[0m\n");
    printf("\033[0;33mGROUND TYPE\n");
    sleep(DELAY_3);
    print_pokemon(ground_pokedex);
    sleep(DELAY_4);
    printf("\033[0m\n\n\n");
  
    destroy_pokedex(pokedex_151);
    destroy_pokedex(fire_pokedex);
    destroy_pokedex(water_pokedex);
    destroy_pokedex(grass_pokedex);
    destroy_pokedex(ground_pokedex);
}




// Write your own Pokedex tests here!


////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////


// Helper functin to create 10 pokemon
static void create_add_10_pokemon(Pokedex pokedex) {
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard = create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();
    Pokemon caterpie = create_caterpie();
    add_pokemon(pokedex,bulbasaur);
    add_pokemon(pokedex,ivysaur);
    add_pokemon(pokedex,venusaur);
    add_pokemon(pokedex,charmander);
    add_pokemon(pokedex,charmeleon);
    add_pokemon(pokedex,charizard);
    add_pokemon(pokedex,squirtle);
    add_pokemon(pokedex,wartortle);
    add_pokemon(pokedex,blastoise);
    add_pokemon(pokedex,caterpie);
}
// Helper functino to create 20 pokemon
static void create_add_20_pokemon(Pokedex pokedex) {
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard = create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();
    Pokemon caterpie = create_caterpie();
    Pokemon metapod = create_metapod();
    Pokemon butterfree = create_butterfree();
    Pokemon weedle = create_weedle();
    Pokemon kakuna = create_kakuna();
    Pokemon beedrill = create_beedrill();
    Pokemon pidgey = create_pidgey();
    Pokemon pidgeotto = create_pidgeotto();
    Pokemon pidgeot = create_pidgeot();
    Pokemon rattata = create_rattata();
    Pokemon raticate = create_raticate();
    add_pokemon(pokedex,bulbasaur);
    add_pokemon(pokedex,ivysaur);
    add_pokemon(pokedex,venusaur);
    add_pokemon(pokedex,charmander);
    add_pokemon(pokedex,charmeleon);
    add_pokemon(pokedex,charizard);
    add_pokemon(pokedex,squirtle);
    add_pokemon(pokedex,wartortle);
    add_pokemon(pokedex,blastoise);
    add_pokemon(pokedex,caterpie);
    add_pokemon(pokedex,metapod);
    add_pokemon(pokedex,butterfree);
    add_pokemon(pokedex,weedle);
    add_pokemon(pokedex,kakuna);
    add_pokemon(pokedex,beedrill);
    add_pokemon(pokedex,pidgey);
    add_pokemon(pokedex,pidgeotto);
    add_pokemon(pokedex,pidgeot);
    add_pokemon(pokedex,rattata);
    add_pokemon(pokedex,raticate);
}


// Helper function to create 151 pokemon
static void create_add_151_pokemon(Pokedex pokedex) {
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard = create_charizard();
    Pokemon squirtle = create_squirtle();
    Pokemon wartortle = create_wartortle();
    Pokemon blastoise = create_blastoise();
    Pokemon caterpie = create_caterpie();
    Pokemon metapod = create_metapod();
    Pokemon butterfree = create_butterfree();
    Pokemon weedle = create_weedle();
    Pokemon kakuna = create_kakuna();
    Pokemon beedrill = create_beedrill();
    Pokemon pidgey = create_pidgey();
    Pokemon pidgeotto = create_pidgeotto();
    Pokemon pidgeot = create_pidgeot();
    Pokemon rattata = create_rattata();
    Pokemon raticate = create_raticate();
    Pokemon spearow = create_spearow();
    Pokemon fearow = create_fearow();
    Pokemon ekans = create_ekans();
    Pokemon arbok = create_arbok();
    Pokemon pikachu = create_pikachu();
    Pokemon raichu = create_raichu();
    Pokemon sandshrew = create_sandshrew();
    Pokemon sandslash = create_sandslash();
    Pokemon nidoranf = create_nidoranf();
    Pokemon nidorina = create_nidorina();
    Pokemon nidoqueen = create_nidoqueen();
    Pokemon nidoranm = create_nidoranm();
    Pokemon nidorino = create_nidorino();
    Pokemon nidoking = create_nidoking();
    Pokemon clefairy = create_clefairy();
    Pokemon clefable = create_clefable();
    Pokemon vulpix = create_vulpix();
    Pokemon ninetales = create_ninetales();
    Pokemon jigglypuff = create_jigglypuff();
    Pokemon wigglytuff = create_wigglytuff();
    Pokemon zubat = create_zubat();
    Pokemon golbat = create_golbat();
    Pokemon oddish = create_oddish();
    Pokemon gloom = create_gloom();
    Pokemon vileplume = create_vileplume();
    Pokemon paras = create_paras();
    Pokemon parasect = create_parasect();
    Pokemon venonat = create_venonat();
    Pokemon venomoth = create_venomoth();
    Pokemon diglett = create_diglett();
    Pokemon dugtrio = create_dugtrio();
    Pokemon meowth = create_meowth();
    Pokemon persian = create_persian();
    Pokemon psyduck = create_psyduck();
    Pokemon golduck = create_golduck();
    Pokemon mankey = create_mankey();
    Pokemon primeape = create_primeape();
    Pokemon growlithe = create_growlithe();
    Pokemon arcanine = create_arcanine();
    Pokemon poliwag = create_poliwag();
    Pokemon poliwhirl = create_poliwhirl();
    Pokemon poliwrath = create_poliwrath();
    Pokemon abra = create_abra();
    Pokemon kadabra = create_kadabra();
    Pokemon alakazam = create_alakazam();
    Pokemon machop = create_machop();
    Pokemon machoke = create_machoke();
    Pokemon machamp = create_machamp();
    Pokemon bellsprout = create_bellsprout();
    Pokemon weepinbell = create_weepinbell();
    Pokemon victreebel = create_victreebel();
    Pokemon tentacool = create_tentacool();
    Pokemon tentacruel = create_tentacruel();
    Pokemon geodude = create_geodude();
    Pokemon graveler = create_graveler();
    Pokemon golem = create_golem();
    Pokemon ponyta = create_ponyta();
    Pokemon rapidash = create_rapidash();
    Pokemon slowpoke = create_slowpoke();
    Pokemon slowbro = create_slowbro();
    Pokemon magnemite = create_magnemite();
    Pokemon magneton = create_magneton();
    Pokemon farfetchd = create_farfetchd();
    Pokemon doduo = create_doduo();
    Pokemon dodrio = create_dodrio();
    Pokemon seel = create_seel();
    Pokemon dewgong = create_dewgong();
    Pokemon grimer = create_grimer();
    Pokemon muk = create_muk();
    Pokemon shellder = create_shellder();
    Pokemon cloyster = create_cloyster();
    Pokemon gastly = create_gastly();
    Pokemon haunter = create_haunter();
    Pokemon gengar = create_gengar();
    Pokemon onix = create_onix();
    Pokemon drowzee = create_drowzee();
    Pokemon hypno = create_hypno();
    Pokemon krabby = create_krabby();
    Pokemon kingler = create_kingler();
    Pokemon voltorb = create_voltorb();
    Pokemon electrode = create_electrode();
    Pokemon exeggcute = create_exeggcute();
    Pokemon exeggutor = create_exeggutor();
    Pokemon cubone = create_cubone();
    Pokemon marowak = create_marowak();
    Pokemon hitmonlee = create_hitmonlee();
    Pokemon hitmonchan = create_hitmonchan();
    Pokemon lickitung = create_lickitung();
    Pokemon koffing = create_koffing();
    Pokemon weezing = create_weezing();
    Pokemon rhyhorn = create_rhyhorn();
    Pokemon rhydon = create_rhydon();
    Pokemon chansey = create_chansey();
    Pokemon tangela = create_tangela();
    Pokemon kangaskhan = create_kangaskhan();
    Pokemon horsea = create_horsea();
    Pokemon seadra = create_seadra();
    Pokemon goldeen = create_goldeen();
    Pokemon seaking = create_seaking();
    Pokemon staryu = create_staryu();
    Pokemon starmie = create_starmie();
    Pokemon mrmime = create_mrmime();
    Pokemon scyther = create_scyther();
    Pokemon jynx = create_jynx();
    Pokemon electabuzz = create_electabuzz();
    Pokemon magmar = create_magmar();
    Pokemon pinsir = create_pinsir();
    Pokemon tauros = create_tauros();
    Pokemon magikarp = create_magikarp();
    Pokemon gyarados = create_gyarados();
    Pokemon lapras = create_lapras();
    Pokemon ditto = create_ditto();
    Pokemon eevee = create_eevee();
    Pokemon vaporeon = create_vaporeon();
    Pokemon jolteon = create_jolteon();
    Pokemon flareon = create_flareon();
    Pokemon porygon = create_porygon();
    Pokemon omanyte = create_omanyte();
    Pokemon omastar = create_omastar();
    Pokemon kabuto = create_kabuto();
    Pokemon kabutops = create_kabutops();
    Pokemon aerodactyl = create_aerodactyl();
    Pokemon snorlax = create_snorlax();
    Pokemon articuno = create_articuno();
    Pokemon zapdos = create_zapdos();
    Pokemon moltres = create_moltres();
    Pokemon dratini = create_dratini();
    Pokemon dragonair = create_dragonair();
    Pokemon dragonite = create_dragonite();
    Pokemon mewtwo = create_mewtwo();
    Pokemon mew = create_mew();
    // Randomised add pokemon
    add_pokemon(pokedex,ponyta);
    add_pokemon(pokedex,zubat);
    add_pokemon(pokedex,bulbasaur);
    add_pokemon(pokedex,metapod);
    add_pokemon(pokedex,ekans);
    add_pokemon(pokedex,meowth);
    add_pokemon(pokedex,rapidash);
    add_pokemon(pokedex,gyarados);
    add_pokemon(pokedex,nidoqueen);
    add_pokemon(pokedex,weezing);
    add_pokemon(pokedex,sandshrew);
    add_pokemon(pokedex,rhyhorn);
    add_pokemon(pokedex,dragonair);
    add_pokemon(pokedex,golduck);
    add_pokemon(pokedex,electrode);
    add_pokemon(pokedex,kadabra);
    add_pokemon(pokedex,venusaur);
    add_pokemon(pokedex,golem);
    add_pokemon(pokedex,mew);
    add_pokemon(pokedex,geodude);
    add_pokemon(pokedex,dratini);
    add_pokemon(pokedex,hitmonlee);
    add_pokemon(pokedex,nidoranm);
    add_pokemon(pokedex,persian);
    add_pokemon(pokedex,vaporeon);
    add_pokemon(pokedex,haunter);
    add_pokemon(pokedex,wartortle);
    add_pokemon(pokedex,mewtwo);
    add_pokemon(pokedex,vileplume);
    add_pokemon(pokedex,diglett);
    add_pokemon(pokedex,bellsprout);
    add_pokemon(pokedex,omastar);
    add_pokemon(pokedex,lapras);
    add_pokemon(pokedex,moltres);
    add_pokemon(pokedex,krabby);
    add_pokemon(pokedex,vulpix);
    add_pokemon(pokedex,pikachu);
    add_pokemon(pokedex,scyther);
    add_pokemon(pokedex,pidgey);
    add_pokemon(pokedex,magnemite);
    add_pokemon(pokedex,shellder);
    add_pokemon(pokedex,mrmime);
    add_pokemon(pokedex,oddish);
    add_pokemon(pokedex,sandslash);
    add_pokemon(pokedex,machamp);
    add_pokemon(pokedex,charmeleon);
    add_pokemon(pokedex,exeggcute);
    add_pokemon(pokedex,koffing);
    add_pokemon(pokedex,jolteon);
    add_pokemon(pokedex,magneton);
    add_pokemon(pokedex,horsea);
    add_pokemon(pokedex,nidoking);
    add_pokemon(pokedex,beedrill);
    add_pokemon(pokedex,nidorino);
    add_pokemon(pokedex,aerodactyl);
    add_pokemon(pokedex,gastly);
    add_pokemon(pokedex,seel);
    add_pokemon(pokedex,arbok);
    add_pokemon(pokedex,dewgong);
    add_pokemon(pokedex,cloyster);
    add_pokemon(pokedex,tauros);
    add_pokemon(pokedex,golbat);
    add_pokemon(pokedex,voltorb);
    add_pokemon(pokedex,tangela);
    add_pokemon(pokedex,dodrio);
    add_pokemon(pokedex,ivysaur);
    add_pokemon(pokedex,charizard);
    add_pokemon(pokedex,snorlax);
    add_pokemon(pokedex,pidgeotto);
    add_pokemon(pokedex,magmar);
    add_pokemon(pokedex,dragonite);
    add_pokemon(pokedex,venomoth);
    add_pokemon(pokedex,blastoise);
    add_pokemon(pokedex,abra);
    add_pokemon(pokedex,slowbro);
    add_pokemon(pokedex,nidoranf);
    add_pokemon(pokedex,zapdos);
    add_pokemon(pokedex,gloom);
    add_pokemon(pokedex,onix);
    add_pokemon(pokedex,weedle);
    add_pokemon(pokedex,graveler);
    add_pokemon(pokedex,ninetales);
    add_pokemon(pokedex,caterpie);
    add_pokemon(pokedex,primeape);
    add_pokemon(pokedex,rhydon);
    add_pokemon(pokedex,ditto);
    add_pokemon(pokedex,electabuzz);
    add_pokemon(pokedex,jigglypuff);
    add_pokemon(pokedex,poliwhirl);
    add_pokemon(pokedex,staryu);
    add_pokemon(pokedex,machop);
    add_pokemon(pokedex,pinsir);
    add_pokemon(pokedex,machoke);
    add_pokemon(pokedex,paras);
    add_pokemon(pokedex,eevee);
    add_pokemon(pokedex,kabuto);
    add_pokemon(pokedex,articuno);
    add_pokemon(pokedex,psyduck);
    add_pokemon(pokedex,spearow);
    add_pokemon(pokedex,seadra);
    add_pokemon(pokedex,muk);
    add_pokemon(pokedex,tentacool);
    add_pokemon(pokedex,parasect);
    add_pokemon(pokedex,nidorina);
    add_pokemon(pokedex,raichu);
    add_pokemon(pokedex,grimer);
    add_pokemon(pokedex,victreebel);
    add_pokemon(pokedex,alakazam);
    add_pokemon(pokedex,hitmonchan);
    add_pokemon(pokedex,marowak);
    add_pokemon(pokedex,magikarp);
    add_pokemon(pokedex,porygon);
    add_pokemon(pokedex,butterfree);
    add_pokemon(pokedex,dugtrio);
    add_pokemon(pokedex,doduo);
    add_pokemon(pokedex,chansey);
    add_pokemon(pokedex,wigglytuff);
    add_pokemon(pokedex,goldeen);
    add_pokemon(pokedex,seaking);
    add_pokemon(pokedex,drowzee);
    add_pokemon(pokedex,kakuna);
    add_pokemon(pokedex,flareon);
    add_pokemon(pokedex,slowpoke);
    add_pokemon(pokedex,poliwrath);
    add_pokemon(pokedex,farfetchd);
    add_pokemon(pokedex,venonat);
    add_pokemon(pokedex,lickitung);
    add_pokemon(pokedex,poliwag);
    add_pokemon(pokedex,omanyte);
    add_pokemon(pokedex,clefairy);
    add_pokemon(pokedex,tentacruel);
    add_pokemon(pokedex,kingler);
    add_pokemon(pokedex,cubone);
    add_pokemon(pokedex,starmie);
    add_pokemon(pokedex,hypno);
    add_pokemon(pokedex,kabutops);
    add_pokemon(pokedex,raticate);
    add_pokemon(pokedex,growlithe);
    add_pokemon(pokedex,fearow);
    add_pokemon(pokedex,weepinbell);
    add_pokemon(pokedex,charmander);
    add_pokemon(pokedex,clefable);
    add_pokemon(pokedex,jynx);
    add_pokemon(pokedex,gengar);
    add_pokemon(pokedex,squirtle);
    add_pokemon(pokedex,pidgeot);
    add_pokemon(pokedex,arcanine);
    add_pokemon(pokedex,exeggutor);
    add_pokemon(pokedex,kangaskhan);
    add_pokemon(pokedex,rattata);
    add_pokemon(pokedex,mankey);

}


// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Venusaur for testing purposes.
static Pokemon create_venusaur(void) {
    Pokemon pokemon = new_pokemon(
            VENUSAUR_ID, VENUSAUR_NAME,
            VENUSAUR_HEIGHT, VENUSAUR_WEIGHT,
            VENUSAUR_FIRST_TYPE,
            VENUSAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Charmander for testing purposes.
static Pokemon create_charmander(void) {
    Pokemon pokemon = new_pokemon(
            CHARMANDER_ID, CHARMANDER_NAME,
            CHARMANDER_HEIGHT, CHARMANDER_WEIGHT,
            CHARMANDER_FIRST_TYPE,
            CHARMANDER_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Charmeleon for testing purposes.
static Pokemon create_charmeleon(void) {
    Pokemon pokemon = new_pokemon(
            CHARMELEON_ID, CHARMELEON_NAME,
            CHARMELEON_HEIGHT, CHARMELEON_WEIGHT,
            CHARMELEON_FIRST_TYPE,
            CHARMELEON_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Charizard for testing purposes.
static Pokemon create_charizard(void) {
    Pokemon pokemon = new_pokemon(
            CHARIZARD_ID, CHARIZARD_NAME,
            CHARIZARD_HEIGHT, CHARIZARD_WEIGHT,
            CHARIZARD_FIRST_TYPE,
            CHARIZARD_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Squirtle for testing purposes.
static Pokemon create_squirtle(void) {
    Pokemon pokemon = new_pokemon(
            SQUIRTLE_ID, SQUIRTLE_NAME,
            SQUIRTLE_HEIGHT, SQUIRTLE_WEIGHT,
            SQUIRTLE_FIRST_TYPE,
            SQUIRTLE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Wartortle for testing purposes.
static Pokemon create_wartortle(void) {
    Pokemon pokemon = new_pokemon(
            WARTORTLE_ID, WARTORTLE_NAME,
            WARTORTLE_HEIGHT, WARTORTLE_WEIGHT,
            WARTORTLE_FIRST_TYPE,
            WARTORTLE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Blastoise for testing purposes.
static Pokemon create_blastoise(void) {
    Pokemon pokemon = new_pokemon(
            BLASTOISE_ID, BLASTOISE_NAME,
            BLASTOISE_HEIGHT, BLASTOISE_WEIGHT,
            BLASTOISE_FIRST_TYPE,
            BLASTOISE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Caterpie for testing purposes.
static Pokemon create_caterpie(void) {
    Pokemon pokemon = new_pokemon(
            CATERPIE_ID, CATERPIE_NAME,
            CATERPIE_HEIGHT, CATERPIE_WEIGHT,
            CATERPIE_FIRST_TYPE,
            CATERPIE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Metapod for testing purposes.
static Pokemon create_metapod(void) {
    Pokemon pokemon = new_pokemon(
            METAPOD_ID, METAPOD_NAME,
            METAPOD_HEIGHT, METAPOD_WEIGHT,
            METAPOD_FIRST_TYPE,
            METAPOD_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Butterfree for testing purposes.
static Pokemon create_butterfree(void) {
    Pokemon pokemon = new_pokemon(
            BUTTERFREE_ID, BUTTERFREE_NAME,
            BUTTERFREE_HEIGHT, BUTTERFREE_WEIGHT,
            BUTTERFREE_FIRST_TYPE,
            BUTTERFREE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Weedle for testing purposes.
static Pokemon create_weedle(void) {
    Pokemon pokemon = new_pokemon(
            WEEDLE_ID, WEEDLE_NAME,
            WEEDLE_HEIGHT, WEEDLE_WEIGHT,
            WEEDLE_FIRST_TYPE,
            WEEDLE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Kakuna for testing purposes.
static Pokemon create_kakuna(void) {
    Pokemon pokemon = new_pokemon(
            KAKUNA_ID, KAKUNA_NAME,
            KAKUNA_HEIGHT, KAKUNA_WEIGHT,
            KAKUNA_FIRST_TYPE,
            KAKUNA_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Beedrill for testing purposes.
static Pokemon create_beedrill(void) {
    Pokemon pokemon = new_pokemon(
            BEEDRILL_ID, BEEDRILL_NAME,
            BEEDRILL_HEIGHT, BEEDRILL_WEIGHT,
            BEEDRILL_FIRST_TYPE,
            BEEDRILL_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Pidgey for testing purposes.
static Pokemon create_pidgey(void) {
    Pokemon pokemon = new_pokemon(
            PIDGEY_ID, PIDGEY_NAME,
            PIDGEY_HEIGHT, PIDGEY_WEIGHT,
            PIDGEY_FIRST_TYPE,
            PIDGEY_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Pidgeotto for testing purposes.
static Pokemon create_pidgeotto(void) {
    Pokemon pokemon = new_pokemon(
            PIDGEOTTO_ID, PIDGEOTTO_NAME,
            PIDGEOTTO_HEIGHT, PIDGEOTTO_WEIGHT,
            PIDGEOTTO_FIRST_TYPE,
            PIDGEOTTO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Pidgeot for testing purposes.
static Pokemon create_pidgeot(void) {
    Pokemon pokemon = new_pokemon(
            PIDGEOT_ID, PIDGEOT_NAME,
            PIDGEOT_HEIGHT, PIDGEOT_WEIGHT,
            PIDGEOT_FIRST_TYPE,
            PIDGEOT_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Rattata for testing purposes.
static Pokemon create_rattata(void) {
    Pokemon pokemon = new_pokemon(
            RATTATA_ID, RATTATA_NAME,
            RATTATA_HEIGHT, RATTATA_WEIGHT,
            RATTATA_FIRST_TYPE,
            RATTATA_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Raticate for testing purposes.
static Pokemon create_raticate(void) {
    Pokemon pokemon = new_pokemon(
            RATICATE_ID, RATICATE_NAME,
            RATICATE_HEIGHT, RATICATE_WEIGHT,
            RATICATE_FIRST_TYPE,
            RATICATE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Spearow for testing purposes.
static Pokemon create_spearow(void) {
    Pokemon pokemon = new_pokemon(
            SPEAROW_ID, SPEAROW_NAME,
            SPEAROW_HEIGHT, SPEAROW_WEIGHT,
            SPEAROW_FIRST_TYPE,
            SPEAROW_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Fearow for testing purposes.
static Pokemon create_fearow(void) {
    Pokemon pokemon = new_pokemon(
            FEAROW_ID, FEAROW_NAME,
            FEAROW_HEIGHT, FEAROW_WEIGHT,
            FEAROW_FIRST_TYPE,
            FEAROW_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ekans for testing purposes.
static Pokemon create_ekans(void) {
    Pokemon pokemon = new_pokemon(
            EKANS_ID, EKANS_NAME,
            EKANS_HEIGHT, EKANS_WEIGHT,
            EKANS_FIRST_TYPE,
            EKANS_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Arbok for testing purposes.
static Pokemon create_arbok(void) {
    Pokemon pokemon = new_pokemon(
            ARBOK_ID, ARBOK_NAME,
            ARBOK_HEIGHT, ARBOK_WEIGHT,
            ARBOK_FIRST_TYPE,
            ARBOK_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Pikachu for testing purposes.
static Pokemon create_pikachu(void) {
    Pokemon pokemon = new_pokemon(
            PIKACHU_ID, PIKACHU_NAME,
            PIKACHU_HEIGHT, PIKACHU_WEIGHT,
            PIKACHU_FIRST_TYPE,
            PIKACHU_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Raichu for testing purposes.
static Pokemon create_raichu(void) {
    Pokemon pokemon = new_pokemon(
            RAICHU_ID, RAICHU_NAME,
            RAICHU_HEIGHT, RAICHU_WEIGHT,
            RAICHU_FIRST_TYPE,
            RAICHU_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Sandshrew for testing purposes.
static Pokemon create_sandshrew(void) {
    Pokemon pokemon = new_pokemon(
            SANDSHREW_ID, SANDSHREW_NAME,
            SANDSHREW_HEIGHT, SANDSHREW_WEIGHT,
            SANDSHREW_FIRST_TYPE,
            SANDSHREW_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Sandslash for testing purposes.
static Pokemon create_sandslash(void) {
    Pokemon pokemon = new_pokemon(
            SANDSLASH_ID, SANDSLASH_NAME,
            SANDSLASH_HEIGHT, SANDSLASH_WEIGHT,
            SANDSLASH_FIRST_TYPE,
            SANDSLASH_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Nidoranf for testing purposes.
static Pokemon create_nidoranf(void) {
    Pokemon pokemon = new_pokemon(
            NIDORANF_ID, NIDORANF_NAME,
            NIDORANF_HEIGHT, NIDORANF_WEIGHT,
            NIDORANF_FIRST_TYPE,
            NIDORANF_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Nidorina for testing purposes.
static Pokemon create_nidorina(void) {
    Pokemon pokemon = new_pokemon(
            NIDORINA_ID, NIDORINA_NAME,
            NIDORINA_HEIGHT, NIDORINA_WEIGHT,
            NIDORINA_FIRST_TYPE,
            NIDORINA_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Nidoqueen for testing purposes.
static Pokemon create_nidoqueen(void) {
    Pokemon pokemon = new_pokemon(
            NIDOQUEEN_ID, NIDOQUEEN_NAME,
            NIDOQUEEN_HEIGHT, NIDOQUEEN_WEIGHT,
            NIDOQUEEN_FIRST_TYPE,
            NIDOQUEEN_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Nidoranm for testing purposes.
static Pokemon create_nidoranm(void) {
    Pokemon pokemon = new_pokemon(
            NIDORANM_ID, NIDORANM_NAME,
            NIDORANM_HEIGHT, NIDORANM_WEIGHT,
            NIDORANM_FIRST_TYPE,
            NIDORANM_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Nidorino for testing purposes.
static Pokemon create_nidorino(void) {
    Pokemon pokemon = new_pokemon(
            NIDORINO_ID, NIDORINO_NAME,
            NIDORINO_HEIGHT, NIDORINO_WEIGHT,
            NIDORINO_FIRST_TYPE,
            NIDORINO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Nidoking for testing purposes.
static Pokemon create_nidoking(void) {
    Pokemon pokemon = new_pokemon(
            NIDOKING_ID, NIDOKING_NAME,
            NIDOKING_HEIGHT, NIDOKING_WEIGHT,
            NIDOKING_FIRST_TYPE,
            NIDOKING_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Clefairy for testing purposes.
static Pokemon create_clefairy(void) {
    Pokemon pokemon = new_pokemon(
            CLEFAIRY_ID, CLEFAIRY_NAME,
            CLEFAIRY_HEIGHT, CLEFAIRY_WEIGHT,
            CLEFAIRY_FIRST_TYPE,
            CLEFAIRY_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Clefable for testing purposes.
static Pokemon create_clefable(void) {
    Pokemon pokemon = new_pokemon(
            CLEFABLE_ID, CLEFABLE_NAME,
            CLEFABLE_HEIGHT, CLEFABLE_WEIGHT,
            CLEFABLE_FIRST_TYPE,
            CLEFABLE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Vulpix for testing purposes.
static Pokemon create_vulpix(void) {
    Pokemon pokemon = new_pokemon(
            VULPIX_ID, VULPIX_NAME,
            VULPIX_HEIGHT, VULPIX_WEIGHT,
            VULPIX_FIRST_TYPE,
            VULPIX_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ninetales for testing purposes.
static Pokemon create_ninetales(void) {
    Pokemon pokemon = new_pokemon(
            NINETALES_ID, NINETALES_NAME,
            NINETALES_HEIGHT, NINETALES_WEIGHT,
            NINETALES_FIRST_TYPE,
            NINETALES_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Jigglypuff for testing purposes.
static Pokemon create_jigglypuff(void) {
    Pokemon pokemon = new_pokemon(
            JIGGLYPUFF_ID, JIGGLYPUFF_NAME,
            JIGGLYPUFF_HEIGHT, JIGGLYPUFF_WEIGHT,
            JIGGLYPUFF_FIRST_TYPE,
            JIGGLYPUFF_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Wigglytuff for testing purposes.
static Pokemon create_wigglytuff(void) {
    Pokemon pokemon = new_pokemon(
            WIGGLYTUFF_ID, WIGGLYTUFF_NAME,
            WIGGLYTUFF_HEIGHT, WIGGLYTUFF_WEIGHT,
            WIGGLYTUFF_FIRST_TYPE,
            WIGGLYTUFF_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Zubat for testing purposes.
static Pokemon create_zubat(void) {
    Pokemon pokemon = new_pokemon(
            ZUBAT_ID, ZUBAT_NAME,
            ZUBAT_HEIGHT, ZUBAT_WEIGHT,
            ZUBAT_FIRST_TYPE,
            ZUBAT_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Golbat for testing purposes.
static Pokemon create_golbat(void) {
    Pokemon pokemon = new_pokemon(
            GOLBAT_ID, GOLBAT_NAME,
            GOLBAT_HEIGHT, GOLBAT_WEIGHT,
            GOLBAT_FIRST_TYPE,
            GOLBAT_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Oddish for testing purposes.
static Pokemon create_oddish(void) {
    Pokemon pokemon = new_pokemon(
            ODDISH_ID, ODDISH_NAME,
            ODDISH_HEIGHT, ODDISH_WEIGHT,
            ODDISH_FIRST_TYPE,
            ODDISH_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Gloom for testing purposes.
static Pokemon create_gloom(void) {
    Pokemon pokemon = new_pokemon(
            GLOOM_ID, GLOOM_NAME,
            GLOOM_HEIGHT, GLOOM_WEIGHT,
            GLOOM_FIRST_TYPE,
            GLOOM_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Vileplume for testing purposes.
static Pokemon create_vileplume(void) {
    Pokemon pokemon = new_pokemon(
            VILEPLUME_ID, VILEPLUME_NAME,
            VILEPLUME_HEIGHT, VILEPLUME_WEIGHT,
            VILEPLUME_FIRST_TYPE,
            VILEPLUME_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Paras for testing purposes.
static Pokemon create_paras(void) {
    Pokemon pokemon = new_pokemon(
            PARAS_ID, PARAS_NAME,
            PARAS_HEIGHT, PARAS_WEIGHT,
            PARAS_FIRST_TYPE,
            PARAS_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Parasect for testing purposes.
static Pokemon create_parasect(void) {
    Pokemon pokemon = new_pokemon(
            PARASECT_ID, PARASECT_NAME,
            PARASECT_HEIGHT, PARASECT_WEIGHT,
            PARASECT_FIRST_TYPE,
            PARASECT_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Venonat for testing purposes.
static Pokemon create_venonat(void) {
    Pokemon pokemon = new_pokemon(
            VENONAT_ID, VENONAT_NAME,
            VENONAT_HEIGHT, VENONAT_WEIGHT,
            VENONAT_FIRST_TYPE,
            VENONAT_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Venomoth for testing purposes.
static Pokemon create_venomoth(void) {
    Pokemon pokemon = new_pokemon(
            VENOMOTH_ID, VENOMOTH_NAME,
            VENOMOTH_HEIGHT, VENOMOTH_WEIGHT,
            VENOMOTH_FIRST_TYPE,
            VENOMOTH_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Diglett for testing purposes.
static Pokemon create_diglett(void) {
    Pokemon pokemon = new_pokemon(
            DIGLETT_ID, DIGLETT_NAME,
            DIGLETT_HEIGHT, DIGLETT_WEIGHT,
            DIGLETT_FIRST_TYPE,
            DIGLETT_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Dugtrio for testing purposes.
static Pokemon create_dugtrio(void) {
    Pokemon pokemon = new_pokemon(
            DUGTRIO_ID, DUGTRIO_NAME,
            DUGTRIO_HEIGHT, DUGTRIO_WEIGHT,
            DUGTRIO_FIRST_TYPE,
            DUGTRIO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Meowth for testing purposes.
static Pokemon create_meowth(void) {
    Pokemon pokemon = new_pokemon(
            MEOWTH_ID, MEOWTH_NAME,
            MEOWTH_HEIGHT, MEOWTH_WEIGHT,
            MEOWTH_FIRST_TYPE,
            MEOWTH_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Persian for testing purposes.
static Pokemon create_persian(void) {
    Pokemon pokemon = new_pokemon(
            PERSIAN_ID, PERSIAN_NAME,
            PERSIAN_HEIGHT, PERSIAN_WEIGHT,
            PERSIAN_FIRST_TYPE,
            PERSIAN_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Psyduck for testing purposes.
static Pokemon create_psyduck(void) {
    Pokemon pokemon = new_pokemon(
            PSYDUCK_ID, PSYDUCK_NAME,
            PSYDUCK_HEIGHT, PSYDUCK_WEIGHT,
            PSYDUCK_FIRST_TYPE,
            PSYDUCK_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Golduck for testing purposes.
static Pokemon create_golduck(void) {
    Pokemon pokemon = new_pokemon(
            GOLDUCK_ID, GOLDUCK_NAME,
            GOLDUCK_HEIGHT, GOLDUCK_WEIGHT,
            GOLDUCK_FIRST_TYPE,
            GOLDUCK_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Mankey for testing purposes.
static Pokemon create_mankey(void) {
    Pokemon pokemon = new_pokemon(
            MANKEY_ID, MANKEY_NAME,
            MANKEY_HEIGHT, MANKEY_WEIGHT,
            MANKEY_FIRST_TYPE,
            MANKEY_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Primeape for testing purposes.
static Pokemon create_primeape(void) {
    Pokemon pokemon = new_pokemon(
            PRIMEAPE_ID, PRIMEAPE_NAME,
            PRIMEAPE_HEIGHT, PRIMEAPE_WEIGHT,
            PRIMEAPE_FIRST_TYPE,
            PRIMEAPE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Growlithe for testing purposes.
static Pokemon create_growlithe(void) {
    Pokemon pokemon = new_pokemon(
            GROWLITHE_ID, GROWLITHE_NAME,
            GROWLITHE_HEIGHT, GROWLITHE_WEIGHT,
            GROWLITHE_FIRST_TYPE,
            GROWLITHE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Arcanine for testing purposes.
static Pokemon create_arcanine(void) {
    Pokemon pokemon = new_pokemon(
            ARCANINE_ID, ARCANINE_NAME,
            ARCANINE_HEIGHT, ARCANINE_WEIGHT,
            ARCANINE_FIRST_TYPE,
            ARCANINE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Poliwag for testing purposes.
static Pokemon create_poliwag(void) {
    Pokemon pokemon = new_pokemon(
            POLIWAG_ID, POLIWAG_NAME,
            POLIWAG_HEIGHT, POLIWAG_WEIGHT,
            POLIWAG_FIRST_TYPE,
            POLIWAG_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Poliwhirl for testing purposes.
static Pokemon create_poliwhirl(void) {
    Pokemon pokemon = new_pokemon(
            POLIWHIRL_ID, POLIWHIRL_NAME,
            POLIWHIRL_HEIGHT, POLIWHIRL_WEIGHT,
            POLIWHIRL_FIRST_TYPE,
            POLIWHIRL_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Poliwrath for testing purposes.
static Pokemon create_poliwrath(void) {
    Pokemon pokemon = new_pokemon(
            POLIWRATH_ID, POLIWRATH_NAME,
            POLIWRATH_HEIGHT, POLIWRATH_WEIGHT,
            POLIWRATH_FIRST_TYPE,
            POLIWRATH_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Abra for testing purposes.
static Pokemon create_abra(void) {
    Pokemon pokemon = new_pokemon(
            ABRA_ID, ABRA_NAME,
            ABRA_HEIGHT, ABRA_WEIGHT,
            ABRA_FIRST_TYPE,
            ABRA_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Kadabra for testing purposes.
static Pokemon create_kadabra(void) {
    Pokemon pokemon = new_pokemon(
            KADABRA_ID, KADABRA_NAME,
            KADABRA_HEIGHT, KADABRA_WEIGHT,
            KADABRA_FIRST_TYPE,
            KADABRA_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Alakazam for testing purposes.
static Pokemon create_alakazam(void) {
    Pokemon pokemon = new_pokemon(
            ALAKAZAM_ID, ALAKAZAM_NAME,
            ALAKAZAM_HEIGHT, ALAKAZAM_WEIGHT,
            ALAKAZAM_FIRST_TYPE,
            ALAKAZAM_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Machop for testing purposes.
static Pokemon create_machop(void) {
    Pokemon pokemon = new_pokemon(
            MACHOP_ID, MACHOP_NAME,
            MACHOP_HEIGHT, MACHOP_WEIGHT,
            MACHOP_FIRST_TYPE,
            MACHOP_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Machoke for testing purposes.
static Pokemon create_machoke(void) {
    Pokemon pokemon = new_pokemon(
            MACHOKE_ID, MACHOKE_NAME,
            MACHOKE_HEIGHT, MACHOKE_WEIGHT,
            MACHOKE_FIRST_TYPE,
            MACHOKE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Machamp for testing purposes.
static Pokemon create_machamp(void) {
    Pokemon pokemon = new_pokemon(
            MACHAMP_ID, MACHAMP_NAME,
            MACHAMP_HEIGHT, MACHAMP_WEIGHT,
            MACHAMP_FIRST_TYPE,
            MACHAMP_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Bellsprout for testing purposes.
static Pokemon create_bellsprout(void) {
    Pokemon pokemon = new_pokemon(
            BELLSPROUT_ID, BELLSPROUT_NAME,
            BELLSPROUT_HEIGHT, BELLSPROUT_WEIGHT,
            BELLSPROUT_FIRST_TYPE,
            BELLSPROUT_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Weepinbell for testing purposes.
static Pokemon create_weepinbell(void) {
    Pokemon pokemon = new_pokemon(
            WEEPINBELL_ID, WEEPINBELL_NAME,
            WEEPINBELL_HEIGHT, WEEPINBELL_WEIGHT,
            WEEPINBELL_FIRST_TYPE,
            WEEPINBELL_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Victreebel for testing purposes.
static Pokemon create_victreebel(void) {
    Pokemon pokemon = new_pokemon(
            VICTREEBEL_ID, VICTREEBEL_NAME,
            VICTREEBEL_HEIGHT, VICTREEBEL_WEIGHT,
            VICTREEBEL_FIRST_TYPE,
            VICTREEBEL_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Tentacool for testing purposes.
static Pokemon create_tentacool(void) {
    Pokemon pokemon = new_pokemon(
            TENTACOOL_ID, TENTACOOL_NAME,
            TENTACOOL_HEIGHT, TENTACOOL_WEIGHT,
            TENTACOOL_FIRST_TYPE,
            TENTACOOL_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Tentacruel for testing purposes.
static Pokemon create_tentacruel(void) {
    Pokemon pokemon = new_pokemon(
            TENTACRUEL_ID, TENTACRUEL_NAME,
            TENTACRUEL_HEIGHT, TENTACRUEL_WEIGHT,
            TENTACRUEL_FIRST_TYPE,
            TENTACRUEL_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Geodude for testing purposes.
static Pokemon create_geodude(void) {
    Pokemon pokemon = new_pokemon(
            GEODUDE_ID, GEODUDE_NAME,
            GEODUDE_HEIGHT, GEODUDE_WEIGHT,
            GEODUDE_FIRST_TYPE,
            GEODUDE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Graveler for testing purposes.
static Pokemon create_graveler(void) {
    Pokemon pokemon = new_pokemon(
            GRAVELER_ID, GRAVELER_NAME,
            GRAVELER_HEIGHT, GRAVELER_WEIGHT,
            GRAVELER_FIRST_TYPE,
            GRAVELER_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Golem for testing purposes.
static Pokemon create_golem(void) {
    Pokemon pokemon = new_pokemon(
            GOLEM_ID, GOLEM_NAME,
            GOLEM_HEIGHT, GOLEM_WEIGHT,
            GOLEM_FIRST_TYPE,
            GOLEM_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ponyta for testing purposes.
static Pokemon create_ponyta(void) {
    Pokemon pokemon = new_pokemon(
            PONYTA_ID, PONYTA_NAME,
            PONYTA_HEIGHT, PONYTA_WEIGHT,
            PONYTA_FIRST_TYPE,
            PONYTA_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Rapidash for testing purposes.
static Pokemon create_rapidash(void) {
    Pokemon pokemon = new_pokemon(
            RAPIDASH_ID, RAPIDASH_NAME,
            RAPIDASH_HEIGHT, RAPIDASH_WEIGHT,
            RAPIDASH_FIRST_TYPE,
            RAPIDASH_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Slowpoke for testing purposes.
static Pokemon create_slowpoke(void) {
    Pokemon pokemon = new_pokemon(
            SLOWPOKE_ID, SLOWPOKE_NAME,
            SLOWPOKE_HEIGHT, SLOWPOKE_WEIGHT,
            SLOWPOKE_FIRST_TYPE,
            SLOWPOKE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Slowbro for testing purposes.
static Pokemon create_slowbro(void) {
    Pokemon pokemon = new_pokemon(
            SLOWBRO_ID, SLOWBRO_NAME,
            SLOWBRO_HEIGHT, SLOWBRO_WEIGHT,
            SLOWBRO_FIRST_TYPE,
            SLOWBRO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Magnemite for testing purposes.
static Pokemon create_magnemite(void) {
    Pokemon pokemon = new_pokemon(
            MAGNEMITE_ID, MAGNEMITE_NAME,
            MAGNEMITE_HEIGHT, MAGNEMITE_WEIGHT,
            MAGNEMITE_FIRST_TYPE,
            MAGNEMITE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Magneton for testing purposes.
static Pokemon create_magneton(void) {
    Pokemon pokemon = new_pokemon(
            MAGNETON_ID, MAGNETON_NAME,
            MAGNETON_HEIGHT, MAGNETON_WEIGHT,
            MAGNETON_FIRST_TYPE,
            MAGNETON_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Farfetchd for testing purposes.
static Pokemon create_farfetchd(void) {
    Pokemon pokemon = new_pokemon(
            FARFETCHD_ID, FARFETCHD_NAME,
            FARFETCHD_HEIGHT, FARFETCHD_WEIGHT,
            FARFETCHD_FIRST_TYPE,
            FARFETCHD_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Doduo for testing purposes.
static Pokemon create_doduo(void) {
    Pokemon pokemon = new_pokemon(
            DODUO_ID, DODUO_NAME,
            DODUO_HEIGHT, DODUO_WEIGHT,
            DODUO_FIRST_TYPE,
            DODUO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Dodrio for testing purposes.
static Pokemon create_dodrio(void) {
    Pokemon pokemon = new_pokemon(
            DODRIO_ID, DODRIO_NAME,
            DODRIO_HEIGHT, DODRIO_WEIGHT,
            DODRIO_FIRST_TYPE,
            DODRIO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Seel for testing purposes.
static Pokemon create_seel(void) {
    Pokemon pokemon = new_pokemon(
            SEEL_ID, SEEL_NAME,
            SEEL_HEIGHT, SEEL_WEIGHT,
            SEEL_FIRST_TYPE,
            SEEL_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Dewgong for testing purposes.
static Pokemon create_dewgong(void) {
    Pokemon pokemon = new_pokemon(
            DEWGONG_ID, DEWGONG_NAME,
            DEWGONG_HEIGHT, DEWGONG_WEIGHT,
            DEWGONG_FIRST_TYPE,
            DEWGONG_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Grimer for testing purposes.
static Pokemon create_grimer(void) {
    Pokemon pokemon = new_pokemon(
            GRIMER_ID, GRIMER_NAME,
            GRIMER_HEIGHT, GRIMER_WEIGHT,
            GRIMER_FIRST_TYPE,
            GRIMER_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Muk for testing purposes.
static Pokemon create_muk(void) {
    Pokemon pokemon = new_pokemon(
            MUK_ID, MUK_NAME,
            MUK_HEIGHT, MUK_WEIGHT,
            MUK_FIRST_TYPE,
            MUK_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Shellder for testing purposes.
static Pokemon create_shellder(void) {
    Pokemon pokemon = new_pokemon(
            SHELLDER_ID, SHELLDER_NAME,
            SHELLDER_HEIGHT, SHELLDER_WEIGHT,
            SHELLDER_FIRST_TYPE,
            SHELLDER_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Cloyster for testing purposes.
static Pokemon create_cloyster(void) {
    Pokemon pokemon = new_pokemon(
            CLOYSTER_ID, CLOYSTER_NAME,
            CLOYSTER_HEIGHT, CLOYSTER_WEIGHT,
            CLOYSTER_FIRST_TYPE,
            CLOYSTER_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Gastly for testing purposes.
static Pokemon create_gastly(void) {
    Pokemon pokemon = new_pokemon(
            GASTLY_ID, GASTLY_NAME,
            GASTLY_HEIGHT, GASTLY_WEIGHT,
            GASTLY_FIRST_TYPE,
            GASTLY_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Haunter for testing purposes.
static Pokemon create_haunter(void) {
    Pokemon pokemon = new_pokemon(
            HAUNTER_ID, HAUNTER_NAME,
            HAUNTER_HEIGHT, HAUNTER_WEIGHT,
            HAUNTER_FIRST_TYPE,
            HAUNTER_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Gengar for testing purposes.
static Pokemon create_gengar(void) {
    Pokemon pokemon = new_pokemon(
            GENGAR_ID, GENGAR_NAME,
            GENGAR_HEIGHT, GENGAR_WEIGHT,
            GENGAR_FIRST_TYPE,
            GENGAR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Onix for testing purposes.
static Pokemon create_onix(void) {
    Pokemon pokemon = new_pokemon(
            ONIX_ID, ONIX_NAME,
            ONIX_HEIGHT, ONIX_WEIGHT,
            ONIX_FIRST_TYPE,
            ONIX_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Drowzee for testing purposes.
static Pokemon create_drowzee(void) {
    Pokemon pokemon = new_pokemon(
            DROWZEE_ID, DROWZEE_NAME,
            DROWZEE_HEIGHT, DROWZEE_WEIGHT,
            DROWZEE_FIRST_TYPE,
            DROWZEE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Hypno for testing purposes.
static Pokemon create_hypno(void) {
    Pokemon pokemon = new_pokemon(
            HYPNO_ID, HYPNO_NAME,
            HYPNO_HEIGHT, HYPNO_WEIGHT,
            HYPNO_FIRST_TYPE,
            HYPNO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Krabby for testing purposes.
static Pokemon create_krabby(void) {
    Pokemon pokemon = new_pokemon(
            KRABBY_ID, KRABBY_NAME,
            KRABBY_HEIGHT, KRABBY_WEIGHT,
            KRABBY_FIRST_TYPE,
            KRABBY_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Kingler for testing purposes.
static Pokemon create_kingler(void) {
    Pokemon pokemon = new_pokemon(
            KINGLER_ID, KINGLER_NAME,
            KINGLER_HEIGHT, KINGLER_WEIGHT,
            KINGLER_FIRST_TYPE,
            KINGLER_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Voltorb for testing purposes.
static Pokemon create_voltorb(void) {
    Pokemon pokemon = new_pokemon(
            VOLTORB_ID, VOLTORB_NAME,
            VOLTORB_HEIGHT, VOLTORB_WEIGHT,
            VOLTORB_FIRST_TYPE,
            VOLTORB_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Electrode for testing purposes.
static Pokemon create_electrode(void) {
    Pokemon pokemon = new_pokemon(
            ELECTRODE_ID, ELECTRODE_NAME,
            ELECTRODE_HEIGHT, ELECTRODE_WEIGHT,
            ELECTRODE_FIRST_TYPE,
            ELECTRODE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Exeggcute for testing purposes.
static Pokemon create_exeggcute(void) {
    Pokemon pokemon = new_pokemon(
            EXEGGCUTE_ID, EXEGGCUTE_NAME,
            EXEGGCUTE_HEIGHT, EXEGGCUTE_WEIGHT,
            EXEGGCUTE_FIRST_TYPE,
            EXEGGCUTE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Exeggutor for testing purposes.
static Pokemon create_exeggutor(void) {
    Pokemon pokemon = new_pokemon(
            EXEGGUTOR_ID, EXEGGUTOR_NAME,
            EXEGGUTOR_HEIGHT, EXEGGUTOR_WEIGHT,
            EXEGGUTOR_FIRST_TYPE,
            EXEGGUTOR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Cubone for testing purposes.
static Pokemon create_cubone(void) {
    Pokemon pokemon = new_pokemon(
            CUBONE_ID, CUBONE_NAME,
            CUBONE_HEIGHT, CUBONE_WEIGHT,
            CUBONE_FIRST_TYPE,
            CUBONE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Marowak for testing purposes.
static Pokemon create_marowak(void) {
    Pokemon pokemon = new_pokemon(
            MAROWAK_ID, MAROWAK_NAME,
            MAROWAK_HEIGHT, MAROWAK_WEIGHT,
            MAROWAK_FIRST_TYPE,
            MAROWAK_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Hitmonlee for testing purposes.
static Pokemon create_hitmonlee(void) {
    Pokemon pokemon = new_pokemon(
            HITMONLEE_ID, HITMONLEE_NAME,
            HITMONLEE_HEIGHT, HITMONLEE_WEIGHT,
            HITMONLEE_FIRST_TYPE,
            HITMONLEE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Hitmonchan for testing purposes.
static Pokemon create_hitmonchan(void) {
    Pokemon pokemon = new_pokemon(
            HITMONCHAN_ID, HITMONCHAN_NAME,
            HITMONCHAN_HEIGHT, HITMONCHAN_WEIGHT,
            HITMONCHAN_FIRST_TYPE,
            HITMONCHAN_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Lickitung for testing purposes.
static Pokemon create_lickitung(void) {
    Pokemon pokemon = new_pokemon(
            LICKITUNG_ID, LICKITUNG_NAME,
            LICKITUNG_HEIGHT, LICKITUNG_WEIGHT,
            LICKITUNG_FIRST_TYPE,
            LICKITUNG_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Koffing for testing purposes.
static Pokemon create_koffing(void) {
    Pokemon pokemon = new_pokemon(
            KOFFING_ID, KOFFING_NAME,
            KOFFING_HEIGHT, KOFFING_WEIGHT,
            KOFFING_FIRST_TYPE,
            KOFFING_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Weezing for testing purposes.
static Pokemon create_weezing(void) {
    Pokemon pokemon = new_pokemon(
            WEEZING_ID, WEEZING_NAME,
            WEEZING_HEIGHT, WEEZING_WEIGHT,
            WEEZING_FIRST_TYPE,
            WEEZING_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Rhyhorn for testing purposes.
static Pokemon create_rhyhorn(void) {
    Pokemon pokemon = new_pokemon(
            RHYHORN_ID, RHYHORN_NAME,
            RHYHORN_HEIGHT, RHYHORN_WEIGHT,
            RHYHORN_FIRST_TYPE,
            RHYHORN_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Rhydon for testing purposes.
static Pokemon create_rhydon(void) {
    Pokemon pokemon = new_pokemon(
            RHYDON_ID, RHYDON_NAME,
            RHYDON_HEIGHT, RHYDON_WEIGHT,
            RHYDON_FIRST_TYPE,
            RHYDON_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Chansey for testing purposes.
static Pokemon create_chansey(void) {
    Pokemon pokemon = new_pokemon(
            CHANSEY_ID, CHANSEY_NAME,
            CHANSEY_HEIGHT, CHANSEY_WEIGHT,
            CHANSEY_FIRST_TYPE,
            CHANSEY_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Tangela for testing purposes.
static Pokemon create_tangela(void) {
    Pokemon pokemon = new_pokemon(
            TANGELA_ID, TANGELA_NAME,
            TANGELA_HEIGHT, TANGELA_WEIGHT,
            TANGELA_FIRST_TYPE,
            TANGELA_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Kangaskhan for testing purposes.
static Pokemon create_kangaskhan(void) {
    Pokemon pokemon = new_pokemon(
            KANGASKHAN_ID, KANGASKHAN_NAME,
            KANGASKHAN_HEIGHT, KANGASKHAN_WEIGHT,
            KANGASKHAN_FIRST_TYPE,
            KANGASKHAN_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Horsea for testing purposes.
static Pokemon create_horsea(void) {
    Pokemon pokemon = new_pokemon(
            HORSEA_ID, HORSEA_NAME,
            HORSEA_HEIGHT, HORSEA_WEIGHT,
            HORSEA_FIRST_TYPE,
            HORSEA_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Seadra for testing purposes.
static Pokemon create_seadra(void) {
    Pokemon pokemon = new_pokemon(
            SEADRA_ID, SEADRA_NAME,
            SEADRA_HEIGHT, SEADRA_WEIGHT,
            SEADRA_FIRST_TYPE,
            SEADRA_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Goldeen for testing purposes.
static Pokemon create_goldeen(void) {
    Pokemon pokemon = new_pokemon(
            GOLDEEN_ID, GOLDEEN_NAME,
            GOLDEEN_HEIGHT, GOLDEEN_WEIGHT,
            GOLDEEN_FIRST_TYPE,
            GOLDEEN_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Seaking for testing purposes.
static Pokemon create_seaking(void) {
    Pokemon pokemon = new_pokemon(
            SEAKING_ID, SEAKING_NAME,
            SEAKING_HEIGHT, SEAKING_WEIGHT,
            SEAKING_FIRST_TYPE,
            SEAKING_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Staryu for testing purposes.
static Pokemon create_staryu(void) {
    Pokemon pokemon = new_pokemon(
            STARYU_ID, STARYU_NAME,
            STARYU_HEIGHT, STARYU_WEIGHT,
            STARYU_FIRST_TYPE,
            STARYU_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Starmie for testing purposes.
static Pokemon create_starmie(void) {
    Pokemon pokemon = new_pokemon(
            STARMIE_ID, STARMIE_NAME,
            STARMIE_HEIGHT, STARMIE_WEIGHT,
            STARMIE_FIRST_TYPE,
            STARMIE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Mrmime for testing purposes.
static Pokemon create_mrmime(void) {
    Pokemon pokemon = new_pokemon(
            MRMIME_ID, MRMIME_NAME,
            MRMIME_HEIGHT, MRMIME_WEIGHT,
            MRMIME_FIRST_TYPE,
            MRMIME_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Scyther for testing purposes.
static Pokemon create_scyther(void) {
    Pokemon pokemon = new_pokemon(
            SCYTHER_ID, SCYTHER_NAME,
            SCYTHER_HEIGHT, SCYTHER_WEIGHT,
            SCYTHER_FIRST_TYPE,
            SCYTHER_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Jynx for testing purposes.
static Pokemon create_jynx(void) {
    Pokemon pokemon = new_pokemon(
            JYNX_ID, JYNX_NAME,
            JYNX_HEIGHT, JYNX_WEIGHT,
            JYNX_FIRST_TYPE,
            JYNX_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Electabuzz for testing purposes.
static Pokemon create_electabuzz(void) {
    Pokemon pokemon = new_pokemon(
            ELECTABUZZ_ID, ELECTABUZZ_NAME,
            ELECTABUZZ_HEIGHT, ELECTABUZZ_WEIGHT,
            ELECTABUZZ_FIRST_TYPE,
            ELECTABUZZ_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Magmar for testing purposes.
static Pokemon create_magmar(void) {
    Pokemon pokemon = new_pokemon(
            MAGMAR_ID, MAGMAR_NAME,
            MAGMAR_HEIGHT, MAGMAR_WEIGHT,
            MAGMAR_FIRST_TYPE,
            MAGMAR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Pinsir for testing purposes.
static Pokemon create_pinsir(void) {
    Pokemon pokemon = new_pokemon(
            PINSIR_ID, PINSIR_NAME,
            PINSIR_HEIGHT, PINSIR_WEIGHT,
            PINSIR_FIRST_TYPE,
            PINSIR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Tauros for testing purposes.
static Pokemon create_tauros(void) {
    Pokemon pokemon = new_pokemon(
            TAUROS_ID, TAUROS_NAME,
            TAUROS_HEIGHT, TAUROS_WEIGHT,
            TAUROS_FIRST_TYPE,
            TAUROS_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Magikarp for testing purposes.
static Pokemon create_magikarp(void) {
    Pokemon pokemon = new_pokemon(
            MAGIKARP_ID, MAGIKARP_NAME,
            MAGIKARP_HEIGHT, MAGIKARP_WEIGHT,
            MAGIKARP_FIRST_TYPE,
            MAGIKARP_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Gyarados for testing purposes.
static Pokemon create_gyarados(void) {
    Pokemon pokemon = new_pokemon(
            GYARADOS_ID, GYARADOS_NAME,
            GYARADOS_HEIGHT, GYARADOS_WEIGHT,
            GYARADOS_FIRST_TYPE,
            GYARADOS_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Lapras for testing purposes.
static Pokemon create_lapras(void) {
    Pokemon pokemon = new_pokemon(
            LAPRAS_ID, LAPRAS_NAME,
            LAPRAS_HEIGHT, LAPRAS_WEIGHT,
            LAPRAS_FIRST_TYPE,
            LAPRAS_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ditto for testing purposes.
static Pokemon create_ditto(void) {
    Pokemon pokemon = new_pokemon(
            DITTO_ID, DITTO_NAME,
            DITTO_HEIGHT, DITTO_WEIGHT,
            DITTO_FIRST_TYPE,
            DITTO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Eevee for testing purposes.
static Pokemon create_eevee(void) {
    Pokemon pokemon = new_pokemon(
            EEVEE_ID, EEVEE_NAME,
            EEVEE_HEIGHT, EEVEE_WEIGHT,
            EEVEE_FIRST_TYPE,
            EEVEE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Vaporeon for testing purposes.
static Pokemon create_vaporeon(void) {
    Pokemon pokemon = new_pokemon(
            VAPOREON_ID, VAPOREON_NAME,
            VAPOREON_HEIGHT, VAPOREON_WEIGHT,
            VAPOREON_FIRST_TYPE,
            VAPOREON_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Jolteon for testing purposes.
static Pokemon create_jolteon(void) {
    Pokemon pokemon = new_pokemon(
            JOLTEON_ID, JOLTEON_NAME,
            JOLTEON_HEIGHT, JOLTEON_WEIGHT,
            JOLTEON_FIRST_TYPE,
            JOLTEON_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Flareon for testing purposes.
static Pokemon create_flareon(void) {
    Pokemon pokemon = new_pokemon(
            FLAREON_ID, FLAREON_NAME,
            FLAREON_HEIGHT, FLAREON_WEIGHT,
            FLAREON_FIRST_TYPE,
            FLAREON_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Porygon for testing purposes.
static Pokemon create_porygon(void) {
    Pokemon pokemon = new_pokemon(
            PORYGON_ID, PORYGON_NAME,
            PORYGON_HEIGHT, PORYGON_WEIGHT,
            PORYGON_FIRST_TYPE,
            PORYGON_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Omanyte for testing purposes.
static Pokemon create_omanyte(void) {
    Pokemon pokemon = new_pokemon(
            OMANYTE_ID, OMANYTE_NAME,
            OMANYTE_HEIGHT, OMANYTE_WEIGHT,
            OMANYTE_FIRST_TYPE,
            OMANYTE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Omastar for testing purposes.
static Pokemon create_omastar(void) {
    Pokemon pokemon = new_pokemon(
            OMASTAR_ID, OMASTAR_NAME,
            OMASTAR_HEIGHT, OMASTAR_WEIGHT,
            OMASTAR_FIRST_TYPE,
            OMASTAR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Kabuto for testing purposes.
static Pokemon create_kabuto(void) {
    Pokemon pokemon = new_pokemon(
            KABUTO_ID, KABUTO_NAME,
            KABUTO_HEIGHT, KABUTO_WEIGHT,
            KABUTO_FIRST_TYPE,
            KABUTO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Kabutops for testing purposes.
static Pokemon create_kabutops(void) {
    Pokemon pokemon = new_pokemon(
            KABUTOPS_ID, KABUTOPS_NAME,
            KABUTOPS_HEIGHT, KABUTOPS_WEIGHT,
            KABUTOPS_FIRST_TYPE,
            KABUTOPS_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Aerodactyl for testing purposes.
static Pokemon create_aerodactyl(void) {
    Pokemon pokemon = new_pokemon(
            AERODACTYL_ID, AERODACTYL_NAME,
            AERODACTYL_HEIGHT, AERODACTYL_WEIGHT,
            AERODACTYL_FIRST_TYPE,
            AERODACTYL_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Snorlax for testing purposes.
static Pokemon create_snorlax(void) {
    Pokemon pokemon = new_pokemon(
            SNORLAX_ID, SNORLAX_NAME,
            SNORLAX_HEIGHT, SNORLAX_WEIGHT,
            SNORLAX_FIRST_TYPE,
            SNORLAX_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Articuno for testing purposes.
static Pokemon create_articuno(void) {
    Pokemon pokemon = new_pokemon(
            ARTICUNO_ID, ARTICUNO_NAME,
            ARTICUNO_HEIGHT, ARTICUNO_WEIGHT,
            ARTICUNO_FIRST_TYPE,
            ARTICUNO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Zapdos for testing purposes.
static Pokemon create_zapdos(void) {
    Pokemon pokemon = new_pokemon(
            ZAPDOS_ID, ZAPDOS_NAME,
            ZAPDOS_HEIGHT, ZAPDOS_WEIGHT,
            ZAPDOS_FIRST_TYPE,
            ZAPDOS_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Moltres for testing purposes.
static Pokemon create_moltres(void) {
    Pokemon pokemon = new_pokemon(
            MOLTRES_ID, MOLTRES_NAME,
            MOLTRES_HEIGHT, MOLTRES_WEIGHT,
            MOLTRES_FIRST_TYPE,
            MOLTRES_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Dratini for testing purposes.
static Pokemon create_dratini(void) {
    Pokemon pokemon = new_pokemon(
            DRATINI_ID, DRATINI_NAME,
            DRATINI_HEIGHT, DRATINI_WEIGHT,
            DRATINI_FIRST_TYPE,
            DRATINI_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Dragonair for testing purposes.
static Pokemon create_dragonair(void) {
    Pokemon pokemon = new_pokemon(
            DRAGONAIR_ID, DRAGONAIR_NAME,
            DRAGONAIR_HEIGHT, DRAGONAIR_WEIGHT,
            DRAGONAIR_FIRST_TYPE,
            DRAGONAIR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Dragonite for testing purposes.
static Pokemon create_dragonite(void) {
    Pokemon pokemon = new_pokemon(
            DRAGONITE_ID, DRAGONITE_NAME,
            DRAGONITE_HEIGHT, DRAGONITE_WEIGHT,
            DRAGONITE_FIRST_TYPE,
            DRAGONITE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Mewtwo for testing purposes.
static Pokemon create_mewtwo(void) {
    Pokemon pokemon = new_pokemon(
            MEWTWO_ID, MEWTWO_NAME,
            MEWTWO_HEIGHT, MEWTWO_WEIGHT,
            MEWTWO_FIRST_TYPE,
            MEWTWO_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Mew for testing purposes.
static Pokemon create_mew(void) {
    Pokemon pokemon = new_pokemon(
            MEW_ID, MEW_NAME,
            MEW_HEIGHT, MEW_WEIGHT,
            MEW_FIRST_TYPE,
            MEW_SECOND_TYPE
    );
    return pokemon;
}










// Helper function to compare whether two Pokemon are the "same", based
// on whether their attributes match (e.g. id, height, weight, etc).
//
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int same_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}

// Write your own helper functions here!

