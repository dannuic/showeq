/*
 * interface.h
 *
 *  ShowEQ Distributed under GPL
 *  http://seq.sourceforge.net/
 */

#ifndef EQINT_H
#define EQINT_H

#include <qwidget.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qframe.h>
#include <qlabel.h>
#include <qlistview.h>
#include <qlayout.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qmainwindow.h>
#include <qhbox.h>
#include <qvbox.h>
#include <qsplitter.h>
#include <qvaluelist.h>
#include <qtimer.h>
#include <qlist.h>
#include <qmessagebox.h>
#include <qtabdialog.h>
#include <qspinbox.h>
#include <qintdict.h>

#include "packet.h"
#include "compassframe.h"
#include "map.h"
#include "experiencelog.h"
#include "combatlog.h"
#include "msgdlg.h"
#include "filtermgr.h"
#include "spawnshell.h"
#include "spellshell.h"
#include "spawnlist.h"
#include "spelllist.h"
#include "player.h"
#include "skilllist.h"
#include "statlist.h"
#include "group.h"
#include "netdiag.h"

//--------------------------------------------------
// typedefs
typedef QValueList<int> MenuIDList;

//--------------------------------------------------
// constants
// maximum number of maps
const int maxNumMaps = 5; 

// This is the base number where the map dock options appear in the
// Docked menu
const int mapDockBase = 5; 

//--------------------------------------------------
// EQInterface
class EQInterface:public QMainWindow
{
   Q_OBJECT

 public:
   EQInterface (QWidget * parent = 0, const char *name = 0);
   ~EQInterface();

   QFont appFont;

 public slots:
   void msgReceived(const QString &);
   void stsMessage(const QString &, int timeout = 0);
   void numSpawns(int);
   void numPacket(int);
   void resetPacket(int);
   void attack2Hand1(const attack2Struct *);
   void action2Message(const action2Struct *);
   void itemShop(const itemInShopStruct* items);
   void moneyOnCorpse(const moneyOnCorpseStruct* money);
   void itemPlayerReceived(const itemOnCorpseStruct* itemc);
   void tradeItemOut(const tradeItemOutStruct* itemt);
   void tradeItemIn(const tradeItemInStruct* itemr);
   void wearItem(const playerItemStruct* itemp);
   void channelMessage(const channelMessageStruct* cmsg, uint32_t, uint8_t);
   void formattedMessage(const formattedMessageStruct* cmsg, uint32_t, uint8_t);
   void random(const randomStruct* randr);
   void emoteText(const emoteTextStruct* emotetext);
   void playerBook(const playerBookStruct* bookp);
   void playerContainer(const playerContainerStruct* containp);
   void inspectData(const inspectDataStruct* inspt);
   void spMessage(const spMesgStruct* spmsg);
   void handleSpell(const memSpellStruct* mem, uint32_t, uint8_t);
   void beginCast(const beginCastStruct* bcast);
   void interruptSpellCast(const badCastStruct *icast);
   void startCast(const startCastStruct* cast);
   void systemMessage(const sysMsgStruct* smsg);
   void moneyUpdate(const moneyUpdateStruct* money);
   void moneyThing(const moneyThingStruct* money);
   void groupInfo(const groupMemberStruct* gmem);
   void summonedItem(const summonedItemStruct*);
   void zoneEntry(const ClientZoneEntryStruct* zsentry);
   void zoneEntry(const ServerZoneEntryStruct* zsentry);
   void zoneChange(const zoneChangeStruct* zoneChange, uint32_t, uint8_t);
   void zoneNew(const newZoneStruct* zoneNew, uint32_t, uint8_t);
   void newGroundItem(const makeDropStruct*, uint32_t, uint8_t);
   void clientTarget(const clientTargetStruct* cts);
   void spawnSelected(const Item* item);
   void spawnConsidered(const Item* item);
   void addItem(const Item* item);
   void delItem(const Item* item);
   void killSpawn(const Item* item);
   void changeItem(const Item* item);
   void handleAlert(const Item* item, alertType type);
   void updateSelectedSpawnStatus(const Item* item);

   void savePrefs(void);
   void addCategory(void);
   void reloadCategories(void);
   void rebuildSpawnList();
   void selectNext(void);
   void selectPrev(void);
   void toggle_log_AllPackets();
   void toggle_log_ZoneData();
   void toggle_log_UnknownData();
   void listSpawns(void);
   void listDrops(void);
   void listCoins(void);
   void listMapInfo(void);
   void dumpSpawns(void);
   void dumpDrops(void);
   void dumpCoins(void);
   void dumpMapInfo(void);
   void launch_editor_filters(void);
   void toggleAutoDetectCharSettings(int id);
   void SetDefaultCharacterClass(int id);
   void SetDefaultCharacterRace(int id);
   void SetDefaultCharacterLevel (int id);
   void toggle_view_StatWin(int id);
   void toggle_view_SkillWin(int id);
   void toggle_view_SpawnListCol( int id );
   void toggle_view_DockedWin( int id );
   
   void selectTheme(int id);
   void ToggleOpCodeMonitoring (int id);
   void ReloadMonitoredOpCodeList (void);
   void toggle_session_tracking(void);

 signals:
   void newMessage(int index);
   void loadFileMap();
   void selectSpawn(const Item* item);
   void saveAllPrefs(void);
   void newZoneName (const QString &); 
   void spellMessage(QString&);

   // Decoder signals
   void backfillPlayer(charProfileStruct *);
   void backfillSpawn(spawnStruct *);

   void combatSignal(int, int, int, int, int);

 private slots:
   void toggle_opt_Fast();
   void toggle_view_UnknownData();
   void toggle_view_ChannelMsgs();
   void toggle_view_ExpWindow();
   void toggle_view_CombatWindow();
   void toggle_opt_ConSelect();
   void toggle_opt_TarSelect();
   void toggle_opt_KeepSelectedVisible();
   void toggle_opt_LogSpawns();
   void toggle_opt_PvPTeams();
   void toggle_opt_PvPDeity();
   void toggle_view_SpawnList();
   void toggle_view_SpellList();
   void toggle_view_PlayerStats();
   void toggle_view_Compass();
   void toggle_view_PlayerSkills();
   void toggle_view_Map(int id);
   void toggle_view_NetDiag();
   void resetMaxMana();
   void createMessageBox();
   void select_filter_file();
   void toggle_view_menubar();
   void toggle_view_statusbar();

 protected:
   void loadFormatStrings();
   void resizeEvent (QResizeEvent *);
   void logFilteredSpawn(const Item* item, uint32_t flag);
   void makeNoise( const Item* item, char* szAudioCmd, char* szSoundType);
   void doAlertCommand(const Item* item, 
		       const QString& command,
		       const QString& audioCue);
   void showMap(int mapNum);
   void showSpawnList(void);
   void showSpellList(void);
   void showCompass(void);
   void showNetDiag(void);

 public:
   EQPlayer*  m_player;
   MapMgr* mapMgr(void) { return m_mapMgr; }

 private:
   MapMgr* m_mapMgr;
   CSpawnList* m_spawnList;
   SpellList* m_spellList;
   EQSkillList* m_skillList;
   EQStatList* m_statList;
   EQPacket*  m_packet;
   FilterMgr* m_filterMgr;
   CategoryMgr* m_categoryMgr;
   SpawnShell* m_spawnShell;
   SpellShell* m_spellShell;
   GroupMgr* m_groupMgr;
   PktLogger* m_pktLogger;
   const Item* m_selectedSpawn;

   QPopupMenu* pNetMenu;
   QPopupMenu* pStatWinMenu;
   QPopupMenu* pSkillWinMenu;
   QPopupMenu* pSpawnListMenu;
   QPopupMenu* pDockedWinMenu;
   QPopupMenu* pCharMenu;
   QPopupMenu* pCharLevelMenu;
   QSpinBox* levelSpinBox;
   QPopupMenu* pCharClassMenu;
   QPopupMenu* pCharRaceMenu;

   CompassFrame* m_compass;
   MapFrame*  m_map[maxNumMaps];
   QSplitter* m_splitV;
   QSplitter* m_splitH;
   QSplitter* m_splitT;
   ExperienceWindow* m_expWindow;
   CombatWindow* m_combatWindow;
   NetDiag* m_netDiag;
   QLabel* m_stsbarSpawns;
   QLabel* m_stsbarStatus;
   QLabel* m_stsbarZone;
   QLabel* m_stsbarID;
   QLabel* m_stsbarExp;
   QLabel* m_stsbarExpAA;
   QLabel* m_stsbarPkt;
   QLabel* m_stsbarEQTime;

   QList<MsgDialog>  m_msgDialogList;   

   bool viewUnknownData;

   int char_ClassID[PLAYER_CLASSES];
   int char_RaceID[PLAYER_RACES];
   int  m_id_log_AllPackets;
   int  m_id_log_ZoneData;
   int  m_id_log_UnknownData;
   int  m_id_opt_OptionsDlg;
   int  m_id_opt_Fast;
   int  m_id_opt_ResetMana;
   int  m_id_view_UnknownData;
   int  m_id_view_ChannelMsgs;
   int  m_id_view_ExpWindow;
   int  m_id_view_CombatWindow;
   int  m_id_view_SpawnList;
   int  m_id_view_PlayerStats;
   int  m_id_view_PlayerSkills;
   int  m_id_view_Compass;
   int  m_id_view_Map[maxNumMaps];
   int  m_id_view_NetDiag;
   int  m_id_view_SpellList;
   int  m_id_view_PlayerStats_Options;
   int  m_id_view_PlayerStats_Stats[LIST_MAXLIST];
   int  m_id_view_PlayerSkills_Options;
   int  m_id_view_PlayerSkills_Languages;
   int  m_id_view_SpawnList_Options;
   int  m_id_view_SpawnList_Cols[SPAWNCOL_MAXCOLS];
   int  m_id_opt_ConSelect;
   int  m_id_opt_TarSelect;
   int  m_id_opt_KeepSelectedVisible;
   int  m_id_opt_LogSpawns;
   int  m_id_opt_PvPTeams;
   int  m_id_opt_PvPDeity;
   int  m_id_net_sessiontrack;
   int  m_packetStartTime;
   int  m_initialcount;

   MenuIDList IDList_StyleMenu;

   QStringList m_StringList;
   QDialog *dialogbox;

   QIntDict<QString> m_formattedMessageStrings;

   bool m_viewChannelMsgs;

   bool m_isSkillListDocked;
   bool m_isStatListDocked;
   bool m_isMapDocked[maxNumMaps];
   bool m_isSpawnListDocked;
   bool m_isSpellListDocked;
   bool m_isCompassDocked;

   
};

#endif // EQINT_H

