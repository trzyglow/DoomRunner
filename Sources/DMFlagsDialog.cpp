//======================================================================================================================
// Project: DoomRunner
//----------------------------------------------------------------------------------------------------------------------
// Author:      Jan Broz (Youda008)
// Created on:  13.5.2019
// Description:
//======================================================================================================================

#include "DMFlagsDialog.hpp"
#include "ui_DMFlagsDialog.h"


#include <cstdint>
#include <climits>

#include <QLineEdit>
#include <QIntValidator>


//======================================================================================================================

DMFlagsDialog::DMFlagsDialog( QWidget * parent, uint32_t & dmflags1, uint32_t & dmflags2 )

	: QDialog( parent )
	, flags1( dmflags1 )
	, flags2( dmflags2 )
{
	ui = new Ui::DMFlagsDialog;
	ui->setupUi( this );

	ui->dmflags1_line->setValidator( new QIntValidator( 0, UINT32_MAX, this ) );  // TODO: unsigned int validator
	ui->dmflags2_line->setValidator( new QIntValidator( 0, UINT32_MAX, this ) );

	ui->dmflags1_line->setText( QString::number( dmflags1 ) );
	ui->dmflags2_line->setText( QString::number( dmflags2 ) );

	updateCheckboxes();
}

DMFlagsDialog::~DMFlagsDialog()
{
	delete ui;
}
/*
void DMFlagsDialog::closeEvent( QCloseEvent * event )
{
	emit dmflagsConfirmed( flags1, flags2 );

	QDialog::closeEvent( event );
}
*/
Flag FALLING_DAMAGE               = { dmflags1, 8, false };
Flag DROP_WEAPON                  = { dmflags2, 2, false };
Flag DOUBLE_AMMO                  = { dmflags2, 64, false };
Flag INF_AMMO                     = { dmflags1, 2048, false };
Flag INF_INVENTORY                = { dmflags2, 65536, false };
Flag NO_MONSTERS                  = { dmflags1, 4096, false };
Flag NO_MONSTERS_TO_EXIT          = { dmflags2, 131072, false };
Flag MONSTERS_RESPAWN             = { dmflags1, 8192, false };
Flag NO_RESPAWN                   = { dmflags2, 16384, false };
Flag ITEMS_RESPAWN                = { dmflags1, 16384, false };
Flag BIG_POWERUPS_RESPAWN         = { dmflags2, 134217728, false };
Flag FAST_MONSTERS                = { dmflags1, 32768, false };
Flag DEGENERATION                 = { dmflags2, 128, false };
Flag ALLOW_AUTO_AIM               = { dmflags2, 8388608, true };
Flag ALLOW_SUICIDE                = { dmflags2, 4194304, true };
Flag ALLOW_JUMP1                  = { dmflags1, 65536, true };
Flag ALLOW_JUMP2                  = { dmflags1, 131072, false };
Flag ALLOW_CROUCH1                = { dmflags1, 4194304, true };
Flag ALLOW_CROUCH2                = { dmflags1, 8388608, false};
Flag ALLOW_FREELOOK1              = { dmflags1, 262144, true };
Flag ALLOW_FREELOOK2              = { dmflags1, 524288, false };
Flag ALLOW_FOV                    = { dmflags1, 1048576, true };
Flag ALLOW_BFG_AIMING             = { dmflags2, 256, true };
Flag ALLOW_AUTOMAP                = { dmflags2, 262144, true };
Flag AUTOMAP_ALLIES               = { dmflags2, 524288, true };
Flag ALLOW_SPYING                 = { dmflags2, 1048576, true };
Flag CHASECAM_CHEAT               = { dmflags2, 2097152, false };
Flag CHECK_AMMO_FOR_WEAPON_SWITCH = { dmflags2, 16777216, true };
Flag ICONS_DEATH_KILLS_ITS_SPAWNS = { dmflags2, 33554432, false };
Flag END_SECTOR_COUNTS_FOR_KILL   = { dmflags2, 67108864, true };

Flag WEAPONS_STAY                 = { dmflags1, 4, false };
Flag ALLOW_POWERUPS               = { dmflags1, 2, true };
Flag ALLOW_HEALTH                 = { dmflags1, 1, true };
Flag ALLOW_ARMOR                  = { dmflags1, 512, true };
Flag SPAWN_FARTHEST               = { dmflags1, 128, false };
Flag SAME_MAP                     = { dmflags1, 64, false };
Flag FORCE_RESPAWN                = { dmflags1, 256, false };
Flag ALLOW_EXIT                   = { dmflags1, 1024, true };
Flag BARRELS_RESPAWN              = { dmflags2, 512, false };
Flag RESPAWN_PROTECTION           = { dmflags2, 1024, false };
Flag LOSE_FRAG_IF_FRAGGED         = { dmflags2, 32768, false };
Flag KEEP_FRAGS_GAINED            = { dmflags2, 8192, false };
Flag NO_TEAM_SWITCHING            = { dmflags2, 16, false };

Flag SPAWN_MULTI_WEAPONS          = { dmflags1, 2097152, true };
Flag LOSE_ENTIRE_INVENTORY        = { dmflags1, 16777216, false };
Flag KEEP_KEYS                    = { dmflags1, 33554432, true };
Flag KEEP_WEAPONS                 = { dmflags1, 67108864, true };
Flag KEEP_ARMOR                   = { dmflags1, 134217728, true };
Flag KEEP_POWERUPS                = { dmflags1, 268435456, true };
Flag KEEP_AMMO                    = { dmflags1, 536870912, true };
Flag LOSE_HALF_AMMO               = { dmflags1, 1073741824, false };
Flag SPAWN_WHERE_DIED             = { dmflags2, 4096, false };

void DMFlagsDialog::on_fallingDamage_toggled( bool checked )
{
	setFlag( FALLING_DAMAGE, checked );
}

void DMFlagsDialog::on_dropWeapon_toggled( bool checked )
{
	setFlag( DROP_WEAPON, checked );
}

void DMFlagsDialog::on_doubleAmmo_toggled( bool checked )
{
	setFlag( DOUBLE_AMMO, checked );
}

void DMFlagsDialog::on_infAmmo_toggled( bool checked )
{
	setFlag( INF_AMMO, checked );
}

void DMFlagsDialog::on_infInventory_toggled( bool checked )
{
	setFlag( INF_INVENTORY, checked );
}

void DMFlagsDialog::on_noMonsters_toggled( bool checked )
{
	setFlag( NO_MONSTERS, checked );
}

void DMFlagsDialog::on_noMonstersToExit_toggled( bool checked )
{
	setFlag( NO_MONSTERS_TO_EXIT, checked );
}

void DMFlagsDialog::on_monstersRespawn_toggled( bool checked )
{
	setFlag( MONSTERS_RESPAWN, checked );
}

void DMFlagsDialog::on_noRespawn_toggled( bool checked )
{
	setFlag( NO_RESPAWN, checked );
}

void DMFlagsDialog::on_itemsRespawn_toggled( bool checked )
{
	setFlag( ITEMS_RESPAWN, checked );
}

void DMFlagsDialog::on_bigPowerupsRespawn_toggled( bool checked )
{
	setFlag( BIG_POWERUPS_RESPAWN, checked );
}

void DMFlagsDialog::on_fastMonsters_toggled( bool checked )
{
	setFlag( FAST_MONSTERS, checked );
}

void DMFlagsDialog::on_degeneration_toggled( bool checked )
{
	setFlag( DEGENERATION, checked );
}

void DMFlagsDialog::on_allowAutoAim_toggled( bool checked )
{
	setFlag( ALLOW_AUTO_AIM, checked );
}

void DMFlagsDialog::on_allowSuicide_toggled( bool checked )
{
	setFlag( ALLOW_SUICIDE, checked );
}

void DMFlagsDialog::on_allowJump_stateChanged( int state )
{
	if (state == 0) {
		setFlag( ALLOW_JUMP1, false );
		setFlag( ALLOW_JUMP2, false );
	} else if (state == 1) {
		setFlag( ALLOW_JUMP1, true );
		setFlag( ALLOW_JUMP2, false );
	} else if (state == 2) {
		setFlag( ALLOW_JUMP1, false );
		setFlag( ALLOW_JUMP2, true );
	}
}

void DMFlagsDialog::on_allowCrouch_stateChanged( int state )
{
	if (state == 0) {
		setFlag( ALLOW_CROUCH1, false );
		setFlag( ALLOW_CROUCH2, false );
	} else if (state == 1) {
		setFlag( ALLOW_CROUCH1, true );
		setFlag( ALLOW_CROUCH2, false );
	} else if (state == 2) {
		setFlag( ALLOW_CROUCH1, false );
		setFlag( ALLOW_CROUCH2, true );
	}
}

void DMFlagsDialog::on_allowFreelook_stateChanged( int state )
{
	if (state == 0) {
		setFlag( ALLOW_FREELOOK1, false );
		setFlag( ALLOW_FREELOOK2, false );
	} else if (state == 1) {
		setFlag( ALLOW_FREELOOK1, true );
		setFlag( ALLOW_FREELOOK2, false );
	} else if (state == 2) {
		setFlag( ALLOW_FREELOOK1, false );
		setFlag( ALLOW_FREELOOK2, true );
	}
}

void DMFlagsDialog::on_allowFOV_toggled( bool checked )
{
	setFlag( ALLOW_FOV, checked );
}

void DMFlagsDialog::on_allowBFGAiming_toggled( bool checked )
{
	setFlag( ALLOW_BFG_AIMING, checked );
}

void DMFlagsDialog::on_allowAutomap_toggled( bool checked )
{
	setFlag( ALLOW_AUTOMAP, checked );
}

void DMFlagsDialog::on_automapAllies_toggled( bool checked )
{
	setFlag( AUTOMAP_ALLIES, checked );
}

void DMFlagsDialog::on_allowSpying_toggled( bool checked )
{
	setFlag( ALLOW_SPYING, checked );
}

void DMFlagsDialog::on_chasecamCheat_toggled( bool checked )
{
	setFlag( CHASECAM_CHEAT, checked );
}

void DMFlagsDialog::on_checkAmmoForWeaponSwitch_toggled( bool checked )
{
	setFlag( CHECK_AMMO_FOR_WEAPON_SWITCH, checked );
}

void DMFlagsDialog::on_iconsDeathKillsItsSpawns_toggled( bool checked )
{
	setFlag( ICONS_DEATH_KILLS_ITS_SPAWNS, checked );
}

void DMFlagsDialog::on_endSectorCountsForKill_toggled( bool checked )
{
	setFlag( END_SECTOR_COUNTS_FOR_KILL, checked );
}

void DMFlagsDialog::on_weaponsStay_toggled( bool checked )
{
	setFlag( WEAPONS_STAY, checked );
}

void DMFlagsDialog::on_allowPowerups_toggled( bool checked )
{
	setFlag( ALLOW_POWERUPS, checked );
}

void DMFlagsDialog::on_allowHealth_toggled( bool checked )
{
	setFlag( ALLOW_HEALTH, checked );
}

void DMFlagsDialog::on_allowArmor_toggled( bool checked )
{
	setFlag( ALLOW_ARMOR, checked );
}

void DMFlagsDialog::on_spawnFarthest_toggled( bool checked )
{
	setFlag( SPAWN_FARTHEST, checked );
}

void DMFlagsDialog::on_sameMap_toggled( bool checked )
{
	setFlag( SAME_MAP, checked );
}

void DMFlagsDialog::on_forceRespawn_toggled( bool checked )
{
	setFlag( FORCE_RESPAWN, checked );
}

void DMFlagsDialog::on_allowExit_toggled( bool checked )
{
	setFlag( ALLOW_EXIT, checked );
}

void DMFlagsDialog::on_barrelsRespawn_toggled( bool checked )
{
	setFlag( BARRELS_RESPAWN, checked );
}

void DMFlagsDialog::on_respawnProtection_toggled( bool checked )
{
	setFlag( RESPAWN_PROTECTION, checked );
}

void DMFlagsDialog::on_loseFragIfFragged_toggled( bool checked )
{
	setFlag( LOSE_FRAG_IF_FRAGGED, checked );
}

void DMFlagsDialog::on_keepFragsGained_toggled( bool checked )
{
	setFlag( KEEP_FRAGS_GAINED, checked );
}

void DMFlagsDialog::on_noTeamSwitching_toggled( bool checked )
{
	setFlag( NO_TEAM_SWITCHING, checked );
}

void DMFlagsDialog::on_spawnMultiWeapons_toggled( bool checked )
{
	setFlag( SPAWN_MULTI_WEAPONS, checked );
}

void DMFlagsDialog::on_loseEntireInventory_toggled( bool checked )
{
	setFlag( LOSE_ENTIRE_INVENTORY, checked );
}

void DMFlagsDialog::on_keepKeys_toggled( bool checked )
{
	setFlag( KEEP_KEYS, checked );
}

void DMFlagsDialog::on_keepWeapons_toggled( bool checked )
{
	setFlag( KEEP_WEAPONS, checked );
}

void DMFlagsDialog::on_keepArmor_toggled( bool checked )
{
	setFlag( KEEP_ARMOR, checked );
}

void DMFlagsDialog::on_keepPowerups_toggled( bool checked )
{
	setFlag( KEEP_POWERUPS, checked );
}

void DMFlagsDialog::on_keepAmmo_toggled( bool checked )
{
	setFlag( KEEP_AMMO, checked );
}

void DMFlagsDialog::on_loseHalfAmmo_toggled( bool checked )
{
	setFlag( LOSE_HALF_AMMO, checked );
}

void DMFlagsDialog::on_spawnWhereDied_toggled( bool checked )
{
	setFlag( SPAWN_WHERE_DIED, checked );
}

void DMFlagsDialog::setFlag( Flag flag, bool enabled )
{
	uint32_t * flags;
	QLineEdit * line;

	if (flag.flags == dmflags1) {
		flags = &flags1;
		line = ui->dmflags1_line;
	} else {
		flags = &flags2;
		line = ui->dmflags2_line;
	}

	if (enabled != flag.defaultVal)
		*flags |= flag.bit;
	else
		*flags &= ~flag.bit;

	line->setText( QString::number( *flags ) );
}

bool DMFlagsDialog::isEnabled( Flag flag )
{
	uint32_t * flags;

	if (flag.flags == dmflags1)
		flags = &flags1;
	else
		flags = &flags2;

	if (flag.defaultVal == 0)
		return (*flags & flag.bit) != 0;
	else
		return (*flags & flag.bit) == 0;
}

void DMFlagsDialog::on_dmflags1_line_textEdited( const QString & )
{
	flags1 = ui->dmflags1_line->text().toUInt();
	updateCheckboxes();
}

void DMFlagsDialog::on_dmflags2_line_textEdited( const QString & )
{
	flags2 = ui->dmflags2_line->text().toUInt();
	updateCheckboxes();
}

void DMFlagsDialog::updateCheckboxes()
{
	if (isEnabled( FALLING_DAMAGE ))
		ui->fallingDamage->setChecked( true );
	if (isEnabled( DROP_WEAPON ))
		ui->dropWeapon->setChecked( true );
	if (isEnabled( DOUBLE_AMMO ))
		ui->doubleAmmo->setChecked( true );
	if (isEnabled( INF_AMMO ))
		ui->infAmmo->setChecked( true );
	if (isEnabled( INF_INVENTORY ))
		ui->infInventory->setChecked( true );
	if (isEnabled( NO_MONSTERS ))
		ui->noMonsters->setChecked( true );
	if (isEnabled( NO_MONSTERS_TO_EXIT ))
		ui->monstersRespawn->setChecked( true );
	if (isEnabled( MONSTERS_RESPAWN ))
		ui->monstersRespawn->setChecked( true );
	if (isEnabled( NO_RESPAWN ))
		ui->noRespawn->setChecked( true );
	if (isEnabled( ITEMS_RESPAWN ))
		ui->itemsRespawn->setChecked( true );
	if (isEnabled( BIG_POWERUPS_RESPAWN ))
		ui->bigPowerupsRespawn->setChecked( true );
	if (isEnabled( FAST_MONSTERS ))
		ui->fastMonsters->setChecked( true );
	if (isEnabled( DEGENERATION ))
		ui->degeneration->setChecked( true );
	if (isEnabled( ALLOW_AUTO_AIM ))
		ui->allowAutoAim->setChecked( true );
	if (isEnabled( ALLOW_SUICIDE ))
		ui->allowSuicide->setChecked( true );
	if (isEnabled( ALLOW_JUMP1 ))
		ui->allowJump->setCheckState( Qt::PartiallyChecked );
	else if (isEnabled( ALLOW_JUMP2 ))
		ui->allowJump->setCheckState( Qt::Checked );
	else
		ui->allowJump->setCheckState( Qt::Unchecked );
	if (isEnabled( ALLOW_CROUCH1 ))
		ui->allowCrouch->setCheckState( Qt::PartiallyChecked );
	else if (isEnabled( ALLOW_CROUCH2 ))
		ui->allowCrouch->setCheckState( Qt::Checked );
	else
		ui->allowCrouch->setCheckState( Qt::Unchecked );
	if (isEnabled( ALLOW_FREELOOK1 ))
		ui->allowFreelook->setCheckState( Qt::PartiallyChecked );
	else if (isEnabled( ALLOW_FREELOOK2 ))
		ui->allowFreelook->setCheckState( Qt::Checked );
	else
		ui->allowFreelook->setCheckState( Qt::Unchecked );
	if (isEnabled( ALLOW_FOV ))
		ui->allowFOV->setChecked( true );
	if (isEnabled( ALLOW_BFG_AIMING ))
		ui->allowBFGAiming->setChecked( true );
	if (isEnabled( ALLOW_AUTOMAP ))
		ui->allowAutomap->setChecked( true );
	if (isEnabled( AUTOMAP_ALLIES ))
		ui->automapAllies->setChecked( true );
	if (isEnabled( ALLOW_SPYING ))
		ui->allowSpying->setChecked( true );
	if (isEnabled( CHASECAM_CHEAT ))
		ui->chasecamCheat->setChecked( true );
	if (isEnabled( CHECK_AMMO_FOR_WEAPON_SWITCH ))
		ui->checkAmmoForWeaponSwitch->setChecked( true );
	if (isEnabled( ICONS_DEATH_KILLS_ITS_SPAWNS ))
		ui->iconsDeathKillsItsSpawns->setChecked( true );
	if (isEnabled( END_SECTOR_COUNTS_FOR_KILL ))
		ui->endSectorCountsForKill->setChecked( true );
	if (isEnabled( WEAPONS_STAY ))
		ui->weaponsStay->setChecked( true );
	if (isEnabled( ALLOW_POWERUPS ))
		ui->allowPowerups->setChecked( true );
	if (isEnabled( ALLOW_HEALTH ))
		ui->allowHealth->setChecked( true );
	if (isEnabled( ALLOW_ARMOR ))
		ui->allowArmor->setChecked( true );
	if (isEnabled( SPAWN_FARTHEST ))
		ui->spawnFarthest->setChecked( true );
	if (isEnabled( SAME_MAP ))
		ui->sameMap->setChecked( true );
	if (isEnabled( FORCE_RESPAWN ))
		ui->forceRespawn->setChecked( true );
	if (isEnabled( ALLOW_EXIT ))
		ui->allowExit->setChecked( true );
	if (isEnabled( BARRELS_RESPAWN ))
		ui->barrelsRespawn->setChecked( true );
	if (isEnabled( RESPAWN_PROTECTION ))
		ui->respawnProtection->setChecked( true );
	if (isEnabled( LOSE_FRAG_IF_FRAGGED ))
		ui->loseFragIfFragged->setChecked( true );
	if (isEnabled( KEEP_FRAGS_GAINED ))
		ui->keepFragsGained->setChecked( true );
	if (isEnabled( NO_TEAM_SWITCHING ))
		ui->noTeamSwitching->setChecked( true );
	if (isEnabled( SPAWN_MULTI_WEAPONS ))
		ui->spawnMultiWeapons->setChecked( true );
	if (isEnabled( LOSE_ENTIRE_INVENTORY ))
		ui->loseEntireInventory->setChecked( true );
	if (isEnabled( KEEP_KEYS ))
		ui->keepKeys->setChecked( true );
	if (isEnabled( KEEP_WEAPONS ))
		ui->keepWeapons->setChecked( true );
	if (isEnabled( KEEP_ARMOR ))
		ui->keepArmor->setChecked( true );
	if (isEnabled( KEEP_POWERUPS ))
		ui->keepPowerups->setChecked( true );
	if (isEnabled( KEEP_AMMO ))
		ui->keepAmmo->setChecked( true );
	if (isEnabled( LOSE_HALF_AMMO ))
		ui->loseHalfAmmo->setChecked( true );
	if (isEnabled( SPAWN_WHERE_DIED ))
		ui->spawnWhereDied->setChecked( true );
}

void DMFlagsDialog::on_confirm_btn_clicked()
{
	close(); // TODO: change to OK/Cancel dialog instead
}