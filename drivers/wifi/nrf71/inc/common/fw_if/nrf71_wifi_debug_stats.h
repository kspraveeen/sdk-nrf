/*
 *
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file
 * @addtogroup nrf71_wifi_fw_if Wi-Fi driver and firmware interface
 * @{
 * @brief Debug interface between host and RPU
 */

#ifndef __NRF71_WIFI_DEBUG_STATS_H__
#define __NRF71_WIFI_DEBUG_STATS_H__

#include <common/fw_if/pack_def.h>

/**
 *  @brief This enum defines various types of statistics.
 */
enum rpu_stats_type {
	/** All statistics includes PHY, LMAC & UMAC */
	RPU_STATS_TYPE_ALL,
	/** Host statistics */
	RPU_STATS_TYPE_HOST,
	/** UMAC statistics */
	RPU_STATS_TYPE_UMAC,
	/** LMAC statistics*/
	RPU_STATS_TYPE_LMAC,
	/** PHY statistics */
	RPU_STATS_TYPE_PHY,
	/** Offloaded Raw TX statistics */
	RPU_STATS_TYPE_OFFLOADED_RAW_TX,
	/** Highest statistics type number currently defined */
	RPU_STATS_TYPE_MAX
};

/** UMAC error event status */
enum UMAC_ERROR_ID {
	/*! UMAC internal memory full */
	UMAC_CORE_MEM_FULL = 0,
};

/**
 * @brief This structure specifies the UMAC (Upper MAC) RX (receive) debug parameters
 *  specifically designed for debugging purpose.
 *
 */

struct umac_rx_dbg_params {
	/** Total lmac events received to UMAC */
	unsigned int lmac_events;
	/** Total Rx events(LMAC_EVENT_RX) received in ISR */
	unsigned int rx_events;
	/** Received coalised events from LMAC */
	unsigned int rx_coalesce_events;
	/** Total Rx packets received from LMAC */
	unsigned int total_rx_pkts_from_lmac;
	/** Maximum RX packets buffered at any point of time in UMAC.*/
	unsigned int max_refill_gap;
	/** Difference between rx packets received from lmac and packets sent to host */
	unsigned int current_refill_gap;
	/** Number of Packets queued to reorder buffer due to out of order */
	unsigned int out_of_order_mpdus;
	/** Number of packets removed from reorder buffer */
	unsigned int reorder_free_mpdus;
	/** Number of Rx packets resubmitted to LMAC by UMAC */
	unsigned int umac_consumed_pkts;
	/** Number of Rx packets sent to Host for resubmiting */
	unsigned int host_consumed_pkts;
	/** Number of packets received in out of order */
	unsigned int reordering_ampdu;
	/** Management frames sent to userspace */
	unsigned int userspace_offload_frames;
	/** Total packets count in RX thread */
	unsigned int rx_packet_total_count;
	/** Number of data packets received */
	unsigned int rx_packet_data_count;
	/** Number of Qos data packets received */
	unsigned int rx_packet_qos_data_count;
	/** Number of protected data packets received */
	unsigned int rx_packet_protected_data_count;
	/** Number of management packets received */
	unsigned int rx_packet_mgmt_count;
	/** Number of beacon packets received */
	unsigned int rx_packet_beacon_count;
	/** Number of probe response packets received */
	unsigned int rx_packet_probe_resp_count;
	/** Number of authentication packets received */
	unsigned int rx_packet_auth_count;
	/** Number of deauthentication packets received */
	unsigned int rx_packet_deauth_count;
	/** Number of assoc response packets received */
	unsigned int rx_packet_assoc_resp_count;
	/** Number of disassociation packets received */
	unsigned int rx_packet_disassoc_count;
	/** Number of action frames received */
	unsigned int rx_packet_action_count;
	/** Number of probe request packets received */
	unsigned int rx_packet_probe_req_count;
	/** Other management packets received */
	unsigned int rx_packet_other_mgmt_count;
	/** Maximum coalised packets received from LMAC in any RX event */
	unsigned int max_coalesce_pkts;
	/** Packets received with null skb pointer from LMAC */
	unsigned int null_skb_pointer_from_lmac;
	unsigned int null_skb_pointer_from_host;
	unsigned int null_skb_pointer_resubmitted;
	unsigned int unexpected_mgmt_pkt;
	/** Number of packets flushed from reorder buffer before going to sleep */
	unsigned int reorder_flush_pkt_count;
	/** Unprotected error data frames received in security mode */
	unsigned int unsecured_data_error;
	/** Packets received with null skb pointer from LMAC in coalesce event */
	unsigned int pkts_in_null_skb_pointer_event;
	unsigned int rx_buffs_resubmit_cnt;
	unsigned int rx_packet_amsdu_cnt;
	unsigned int rx_packet_mpdu_cnt;
	unsigned int rx_err_secondary_pkt;
	unsigned int rx_err_invalid_pkt_info_type;
} __NRF_WIFI_PKD;

/**
 * @brief This structure specifies the UMAC TX (transmit) debug parameters used for
 *  debugging purposes.
 *
 */
struct umac_tx_dbg_params {
	/** Total number of tx commands received from host */
	unsigned int tx_cmd;
	/** Non coalesce packets received */
	unsigned int tx_non_coalesce_pkts_rcvd_from_host;
	/** coalesce packets received */
	unsigned int tx_coalesce_pkts_rcvd_from_host;
	/** Maximum number of coalesce packets received in any
	 *  TX command coalesce packets received
	 */
	unsigned int tx_max_coalesce_pkts_rcvd_from_host;
	/** Maximum Tx commands currently in process at any point of time in UMAC */
	unsigned int tx_cmds_max_used;
	/** Number of Tx commands that are currently in process in UMAC */
	unsigned int tx_cmds_currently_in_use;
	/** Number of tx done events sent to host */
	unsigned int tx_done_events_send_to_host;
	/** Number of tx done success packets sent to host */
	unsigned int tx_done_success_pkts_to_host;
	/** Number of tx done failure packets sent to host */
	unsigned int tx_done_failure_pkts_to_host;
	/** Number of packets received from host that needs to be encrypted */
	unsigned int tx_cmds_with_crypto_pkts_rcvd_from_host;
	/** Number of packets received from host that need not to be encrypted */
	unsigned int tx_cmds_with_non_crypto_pkts_rcvd_from_host;
	/** Number of broadcast	packets received from host */
	unsigned int tx_cmds_with_broadcast_pkts_rcvd_from_host;
	/** Number of multicast	packets received from host */
	unsigned int tx_cmds_with_multicast_pkts_rcvd_from_host;
	/** Number of unicast packets received from host */
	unsigned int tx_cmds_with_unicast_pkts_rcvd_from_host;
	/** UMAC internal count */
	unsigned int xmit;
	/** Number of addba requests sent */
	unsigned int send_addba_req;
	/** Total ADD BA responses received from host */
	unsigned int addba_resp;
	/** Total packets received in softmac tx function */
	unsigned int softmac_tx;
	/** Number of packets generated internally in UMAC */
	unsigned int internal_pkts;
	/** Number of packets Received from host */
	unsigned int external_pkts;
	/** Total tx commmands sent to lmac */
	unsigned int tx_cmds_to_lmac;
	/** Tx dones received from LMAC */
	unsigned int tx_dones_from_lmac;
	/** Total commands sent to lmac in UMAC hal */
	unsigned int total_cmds_to_lmac;
	unsigned int cmdq_empty;
	/** Number of data packets sent */
	unsigned int tx_packet_data_count;
	/** Number of management packets sent */
	unsigned int tx_packet_mgmt_count;
	/** Number of beacon packets sent */
	unsigned int tx_packet_beacon_count;
	/** Number of probe request packets sent */
	unsigned int tx_packet_probe_req_count;
	/** Number of authentication packets sent */
	unsigned int tx_packet_auth_count;
	/** Number of deauthentication packets sent */
	unsigned int tx_packet_deauth_count;
	/** Number of association request packets sent */
	unsigned int tx_packet_assoc_req_count;
	/** Number of disassociation packets sent */
	unsigned int tx_packet_disassoc_count;
	/** Number of action packets sent */
	unsigned int tx_packet_action_count;
	/** Other management packets sent */
	unsigned int tx_packet_other_mgmt_count;
	/** Number of Non management packets sent */
	unsigned int tx_packet_non_mgmt_data_count;
	/** Number of EAPOL packets sent */
	unsigned int tx_packet_eapol_count;
} __NRF_WIFI_PKD;

/**
 * @brief This structure specifies the UMAC command and event debug parameters used for
 *  debugging purpose.
 *
 */
struct umac_cmd_evnt_dbg_params {
	/** Number of command init received from host */
	unsigned char cmd_init;
	/** Number of init_done events sent to host */
	unsigned char event_init_done;
	/** Number of rf test command received from host */
	unsigned char cmd_rf_test;
	/** Number of connect command received from host */
	unsigned char cmd_connect;
	/** Number of get_stats command received from host */
	unsigned int cmd_get_stats;
	/** Number of power save state events sent to host */
	unsigned int event_ps_state;
	/** Unused*/
	unsigned int cmd_set_reg;
	/** Number of get regulatory commands received from host */
	unsigned int cmd_get_reg;
	/** Number of request set regulatory commands received from host */
	unsigned int cmd_req_set_reg;
	/** Number of trigger scan commands received from host */
	unsigned int cmd_trigger_scan;
	/** Number of scan done events sent to host */
	unsigned int event_scan_done;
	/** Number of get scan commands received from the host to get scan results */
	unsigned int cmd_get_scan;
	unsigned int scan_cmd_fail;
	/** Number of scan commands sent to LMAC */
	unsigned int umac_scan_req;
	/** Number of scan complete events received from LMAC */
	unsigned int umac_scan_complete;
	/** Number of scan requests received from host when previous scan is in progress */
	unsigned int umac_scan_busy;
	unsigned int umac_scan_abort;
	unsigned int umac_scan_abort_complete;
	unsigned int umac_scan_abort_fail;
	/** Number of authentication requests received from host */
	unsigned int cmd_auth;
	/** Number of association requests received from host */
	unsigned int cmd_assoc;
	/** Number of deauthentication requests received from host */
	unsigned int cmd_deauth;
	/** Number of register frame commands received from host to register
	 *  a management frame type which should be passed to host
	 */
	unsigned int cmd_register_frame;
	/** Number of command frames from host which will be used for
	 *  transmitting management frames
	 */
	unsigned int cmd_frame;
	/** Number of delete key commands from host */
	unsigned int cmd_del_key;
	/** Number of new key commands received from host */
	unsigned int cmd_new_key;
	/** Number of set key commands received from host */
	unsigned int cmd_set_key;
	/** Number of get key commands received from host */
	unsigned int cmd_get_key;
	/** Number of beacon hint events sent to host */
	unsigned int event_beacon_hint;
	/** Number of regulatory change events sent to host when regulatory change command
	 *  received from host such as in response to command NL80211_CMD_REG_CHANGE
	 */
	unsigned int event_reg_change;
	/** Number of regulatory change events sent to host other than
	 *  host request for regulatory change
	 */
	unsigned int event_wiphy_reg_change;
	/** Number of set station commands received from host */
	unsigned int cmd_set_station;
	/** Number of new station commands received from host */
	unsigned int cmd_new_station;
	/** Number of del station commands received from host */
	unsigned int cmd_del_station;
	/** Number of new interface commands received from host */
	unsigned int cmd_new_interface;
	/** Number of set interface commands received from host */
	unsigned int cmd_set_interface;
	/** Number of get interface commands received from host */
	unsigned int cmd_get_interface;
	/** Number of set_ifflags commands received from host */
	unsigned int cmd_set_ifflags;
	/** Number of set_ifflags events sent to host */
	unsigned int cmd_set_ifflags_done;
	/** Number of set bss command received from host */
	unsigned int cmd_set_bss;
	/** Number of set wiphy command received from host */
	unsigned int cmd_set_wiphy;
	/** Number of start access point command received from host */
	unsigned int cmd_start_ap;
	/** Number of power save configuration commands sent to LMAC */
	unsigned int LMAC_CMD_PS;
	/** Current power save state configured to LMAC through LMAC_CMD_PS command */
	unsigned int CURR_STATE;
} __NRF_WIFI_PKD;

/**
 * @brief UMAC scan debug counters (separate from @ref umac_cmd_evnt_dbg_params).
 */
struct umac_scan_dbg_params {
	/** NL80211_CMD_TRIGGER_SCAN received from host */
	unsigned int scan_req_from_host;
	/** Trigger-scan with display scan_reason */
	unsigned int display_scan_req_from_host;
	/** Trigger-scan with connect scan_reason */
	unsigned int connect_scan_req_from_host;
	/** LMAC scan commands for 2.4 GHz */
	unsigned int scan_req_to_lmac_2g;
	/** LMAC scan commands for 5 GHz */
	unsigned int scan_req_to_lmac_5g;
	/** LMAC scan commands for 6 GHz */
	unsigned int scan_req_to_lmac_6g;
	/** Scan-complete events from LMAC attributed to 2.4 GHz */
	unsigned int scan_complete_from_lmac_2g;
	/** Scan-complete events from LMAC attributed to 5 GHz */
	unsigned int scan_complete_from_lmac_5g;
	/** Scan-complete events from LMAC attributed to 6 GHz */
	unsigned int scan_complete_from_lmac_6g;
	/** Scan-done notifications toward upper layers (cfg80211) */
	unsigned int scan_done_to_host;
} __NRF_WIFI_PKD;

/**
 * @brief This structure specifies the UMAC interface debug parameters used for debugging purpose.
 *
 */
struct nrf_wifi_interface_stats {
	/** Number of unicast packets sent */
	unsigned int tx_unicast_pkt_count;
	/** Number of multicast packets sent */
	unsigned int tx_multicast_pkt_count;
	/** Number of broadcast packets sent */
	unsigned int tx_broadcast_pkt_count;
	/** Number of tx data bytes sent */
	unsigned int tx_bytes;
	/** Number of unicast packets received */
	unsigned int rx_unicast_pkt_count;
	/** Number of multicast packets received */
	unsigned int rx_multicast_pkt_count;
	/** Number of broadcast packets received */
	unsigned int rx_broadcast_pkt_count;
	/** Number of beacon packets received */
	unsigned int rx_beacon_success_count;
	/** Number of beacon packets missed */
	unsigned int rx_beacon_miss_count;
	/** Number of rx data bytes received */
	unsigned int rx_bytes;
	/** Number of packets with checksum mismatch received */
	unsigned int rx_checksum_error_count;
	/** Number of duplicate packets received */
	unsigned int replay_attack_drop_cnt;
} __NRF_WIFI_PKD;

struct umac_sleep_stats {
	unsigned int sleep_req;
	unsigned int sleep_req_succ;
	unsigned int sleep_req_fail;
	unsigned int sleep_status_to_lmac;
	unsigned int umac_init;
	unsigned int umac_init_warmboot;
	unsigned int reorder_not_empty;
	unsigned int outstanding_cmds;
	unsigned int umac_init_coldboot;
	unsigned int not_station;
	unsigned int authenticating;
	unsigned int associating;
	unsigned int cmd_processing;
	unsigned int tx_done_pending;
	unsigned int tx_cmds_currently_in_use;
	unsigned int events_pending_list_gg;
	unsigned int HPQM_CMD_NOT_EMPTY;
	unsigned int HPQM_EVENTQ_NOT_EMPTY;
	unsigned int pending_addba_resp;
	unsigned int get_channel;
	unsigned int rx_pending;
	unsigned int pre_init;
	unsigned int rx_mbox_pending;
	unsigned int tx_mbox_pending;
	unsigned int pending_cmd_resubmit;
	unsigned int umac_goto_sleep;
	unsigned int max_twt_awake_cnt;
};
/**
 * @brief This structure specifies the UMAC SoftAP debug parameters used for debugging purpose.
 *
 */
struct nrf_wifi_softap_stats {

} __NRF_WIFI_PKD;

/**
 * @brief This structure specifies the UMAC  debug parameters used for debugging purpose.
 *
 */
struct nrf_wifi_mempools_stats {

} __NRF_WIFI_PKD;

/**
 * @brief This structure specifies the UMAC misc debug parameters used for debugging purpose.
 *
 */
struct nrf_wifi_misc_stats {
	/** Total events posted to UMAC RX thread from LMAC */
	unsigned int rx_mbox_post;
	/** Total events received to UMAC RX thread from LMAC */
	unsigned int rx_mbox_receive;
	/** Messages posted  to TX mbox from timer ISR */
	unsigned int timer_mbox_post;
	/** Messages received from timer ISR */
	unsigned int timer_mbox_rcv;
	/** Messages posted to TX mbox from work scheduler */
	unsigned int work_mbox_post;
	/** Messages received from work scheduler */
	unsigned int work_mbox_rcv;
	/** Messages posted to TX mbox from tasklet function */
	unsigned int tasklet_mbox_post;
	/** Messages received from tasklet function */
	unsigned int tasklet_mbox_rcv;
	/** Number of times where requested buffer size is not available
	 *  and allocated from next available memory buffer
	 */
	unsigned int alloc_buf_fail;
	/** Number of twt requests sent on air */
	unsigned int twt_req_sent;
	/** Number of TWT response info events sent to lmac */
	unsigned int twt_info_sent_to_lmac;
	/** Number of TWT teardown info events sent to lmac */
	unsigned int twt_teardown_info_sent_to_lmac;
	/** Number of FTM requests sent to LMAC */
	unsigned int ftm_req_info_sent_to_lmac;
	/** Number of FTM responses received from LMAC */
	unsigned int ftm_resp_rcvd;
	/** Number of gas requests sent */
	unsigned int gas_req_sent;
	/** Number of gas responses received */
	unsigned int gas_resp_received;
	/** Number of gas comeback requests sent */
	unsigned int gas_comeback_req_sent;
	/** Number of neighbor requests sent */
	unsigned int neighbor_req_sent;
	/** Number of neighbor responses received */
	unsigned int neighbor_resp_received;
	/** Number of IPC tx initialisation failures*/
	unsigned int ipc_tx_init_fail;
	/** Number of IPC rx initialisation failures*/
	unsigned int ipc_rx_init_fail;
	/** Number of IPC bind failures*/
	unsigned int ipc_bind_fail;
	/** Number of IPC ring buffer size failures*/
	unsigned int ipc_ring_buf_size_fail;
	/** Number of IPC mem configuration failures*/
	unsigned int ipc_mem_config_fail;

} __NRF_WIFI_PKD;

struct umac_raw_stats {
		unsigned int raw_tx_from_host;
		unsigned int raw_tx_to_lmac;
		unsigned int raw_tx_dones_from_lmac;
		unsigned int raw_tx_dones_to_host;
		unsigned int total_rx_pkts_from_lmac;
		unsigned int total_raw_rx_pkts_from_lmac;
		unsigned int valid_raw_rx_pkts_from_lmac;
		unsigned int raw_rx_pkts_to_host;
} __NRF_WIFI_PKD;

struct umac_ap_stats {
	unsigned int ap_bss_info_changed;
	unsigned int enable_beacon;
	unsigned int del_bcn_timer;
	unsigned int bcn_timer_expiry;
	unsigned int bcn_enabled_flag;
} __NRF_WIFI_PKD;


/**
 * @brief This structure defines the UMAC debug statistics. It contains the necessary parameters
 *  and fields used to gather and present debugging statistics within the UMAC layer.
 *
 */
struct rpu_umac_stats {
	/** Transmit debug statistics @ref umac_tx_dbg_params */
	struct umac_tx_dbg_params tx_dbg_params;
	/** Receive debug statistics @ref umac_rx_dbg_params */
	struct umac_rx_dbg_params rx_dbg_params;
	/** Command Event debug statistics @ref umac_cmd_evnt_dbg_params */
	struct umac_cmd_evnt_dbg_params cmd_evnt_dbg_params;
	/** Scan debug statistics @ref umac_scan_dbg_params */
	struct umac_scan_dbg_params scan_dbg_params;
	/** Interface debug parameters @ref nrf_wifi_interface_stats */
	struct nrf_wifi_interface_stats interface_data_stats;

} __NRF_WIFI_PKD;

enum UMAC_STATS_CATEGORY {
	UMAC_CMD_EVENT_DEBUG_PARAMS = (1 << 0),
	UMAC_TX_DEBUG_PARAMS = (1 << 1),
	UMAC_RX_DEBUG_PARAMS = (1 << 2),
	UMAC_SLEEP_DEBUG_PARAMS = (1 << 4),
	UMAC_INTERFACE_DEBUG_PARAMS = (1 << 5),
	UMAC_REORDER_DEBUG_PARAMS = (1 << 6),
	UMAC_MEMPOOLS_DEBUG_PARAMS = (1 << 7),
	UMAC_SOFTAP_DEBUG_PARAMS = (1 << 8),
	UMAC_RAWTXRX_DEBUG_PARAMS = (1 << 9),
	UMAC_MISC_DEBUG_PARAMS = (1 << 10),
	UMAC_SCAN_DEBUG_PARAMS = (1 << 11),
};

struct umac_debug_stats {
	unsigned int stats_category;
	union {
		/** Transmit debug statistics @ref umac_tx_dbg_params */
		struct umac_tx_dbg_params tx_dbg_params;
		/** Receive debug statistics @ref umac_rx_dbg_params */
		struct umac_rx_dbg_params rx_dbg_params;
		/** Command Event debug statistics @ref umac_cmd_evnt_dbg_params */
		struct umac_cmd_evnt_dbg_params cmd_evnt_dbg_params;
		/** Scan debug statistics @ref umac_scan_dbg_params */
		struct umac_scan_dbg_params scan_dbg_params;
		/** Interface debug parameters @ref nrf_wifi_interface_stats */
		struct nrf_wifi_interface_stats interface_data_stats;
		struct nrf_wifi_mempools_stats mempools_dbg_stats;
		struct nrf_wifi_softap_stats softap_dbg_stats;
		struct nrf_wifi_misc_stats misc_dbg_stats;
		struct umac_raw_stats raw_stats;
		struct umac_sleep_stats sleep_stats;
	};
} __NRF_WIFI_PKD;

#define SLEEP_DEBUG_BUFFER 32

struct lmac_he_stats {
	unsigned int trigger_pkt_cnt;
	unsigned int trigger_aid_matched_cnt;
	unsigned int basic;
	unsigned int bfrp;
	unsigned int mu_bar;
	unsigned int mu_rts;
	unsigned int bsrp;
	unsigned int gcr_mu_bar;
	unsigned int bqrp;
	unsigned int nfrp;
	unsigned int aid_matched_basic;
	unsigned int aid_matched_bfrp;
	unsigned int aid_matched_mu_bar;
	unsigned int aid_matched_mu_rts;
	unsigned int aid_matched_bsrp;
	unsigned int aid_matched_gcr_mu_bar;
	unsigned int aid_matched_bqrp;
	unsigned int aid_matched_nfrp;
	unsigned int edca_switch_cnt;
	unsigned int mu_edca_triggered_cnt;
} __NRF_WIFI_PKD;

struct phy_if_stats {
	unsigned int phy_init_fail_cnt;
	unsigned int phy_ch_switch_fail_cnt;
	unsigned int phy_config_fail_cnt;
	unsigned int phy_config_power_cnt;
	unsigned int rf_test_cmd;
	unsigned int cmd_pwr_mon;
	unsigned int cmd_pwr_mon_all;
	unsigned int vbat_mon;
	unsigned int temp;
	unsigned int lfc_err;
};

struct lmac_common_stats {
	unsigned int general_purpose_timer_isr_cnt;
	unsigned int lmac_task_inprogress;
	unsigned int current_cmd;
	unsigned int cmds_going_to_wait_list;
	unsigned int unexpected_internal_cmd_during_umac_wait;
	unsigned int lmac_rx_isr_inprogress;
	unsigned int hw_timer_isr_inprogress;
	unsigned int deagg_isr_inprogress;
	unsigned int tx_isr_inprogress;
	unsigned int channel_switch_inprogress;
	unsigned int rpu_lockup_event;
	unsigned int rpu_lockup_cnt;
	unsigned int rpu_lockup_recovery_done;
	unsigned int reset_cmd_cnt;
	unsigned int reset_complete_event_cnt;
	unsigned int commad_ent_default;
	unsigned int lmac_enable_cnt;
	unsigned int lmac_disable_cnt;
	unsigned int lmac_error_cnt;
	unsigned int unable_gen_event;
	unsigned int mem_pool_full_cnt;
	unsigned int ch_prog_cmd_cnt;
	unsigned int channel_prog_done;
	unsigned int connect_lost_status;
	unsigned int tx_core_pool_full_cnt;
	unsigned int patch_debug_cnt;
	unsigned int fw_error_event_cnt;
	unsigned int tx_deinit_cmd_cnt;
	unsigned int tx_deinit_done_cnt;
	unsigned int internal_buf_pool_null;
	unsigned int rx_buffer_cmd;
	unsigned int wait_for_tx_done_loop;
	unsigned int cca_busy;
	unsigned int temp_measure_window_expired;
	unsigned int temp_inter_pool_full;
	unsigned int lmac_internal_cmd;
	unsigned int measure_temp_vbat;
	unsigned int fresh_calib_cnt;
	unsigned int coex_event_cnt;
	unsigned int coex_cmd_cnt;
	unsigned int coex_isr_cnt;
	unsigned int block_wlan_traffic_cnt;
	unsigned int un_block_wlan_traffic_cnt;
	unsigned int p2p_no_a_cnt;
	unsigned int scan_timer_task_pending;
	unsigned int scan_timer_task_complete;
	unsigned int coex_request_fail_cnt;
};

struct lmac_scan_stats {
	unsigned int scan_req;
	unsigned int scan_complete;
	unsigned int scan_abort_req;
	unsigned int scan_abort_complete;
	unsigned int scan_probe_fail;
	unsigned int scan_function_inprogress;
	unsigned int scan_event;
	unsigned int current_scan_channel;
	unsigned int current_scan_band;
};

struct lmac_tx_stats {
	unsigned int tx_pkt_cnt;
	unsigned int tx_pkt_done_cnt;
	unsigned int tx_pkt_success;
	unsigned int tx_pkt_underrun;
	unsigned int unknown_status;
	unsigned int agg_tx_timeout;
	unsigned int agg_phy_cca_abort;
	unsigned int bt_abort_at_start;
	unsigned int bt_abort_at_end;
	unsigned int scan_pkt_cnt;
	unsigned int internal_pkt_cnt;
	unsigned int internal_pkt_done_cnt;
	unsigned int dcp_submit_cnt;
	unsigned int edca_isr_cnt;
	unsigned int tx_dma_complete;
	unsigned int ack_resp_cnt;
	unsigned int tx_timeout;
	unsigned int tx_drop_cnt;
	unsigned int blocked_tx_pkt_cnt;
	unsigned int dbg_tx_invalid_tx_vect;
	unsigned int dbg_tx_abort_cnt;
	unsigned int ignore_ack_frame;
	unsigned int edca_tx_abort_cnt;
	unsigned int tx_block_ack_fail_cnt;
	unsigned int data_frame_cnt;
	unsigned int qos_data_frame_cnt;
	unsigned int ctrl_frame_cnt;
	unsigned int mgmt_frame_cnt;
	unsigned int beacon_frame_cnt;
	unsigned int auth_req_frame_cnt;
	unsigned int deauth_frame_cnt;
	unsigned int assoc_req_frame_cnt;
	unsigned int assoc_response_frame_cnt;
	unsigned int re_assoc_req_frame_cnt;
	unsigned int re_assoc_response_frame_cnt;
	unsigned int de_assoc_req_cnt;
	unsigned int probe_req_cnt;
	unsigned int probe_response_cnt;
	unsigned int ht_ctrl_field;
	unsigned int keep_alive_frame_success;
	unsigned int keep_alive_frame_fail;
};


struct lmac_rx_stats {
	unsigned int deagg_isr;
	unsigned int lmac_rxisr_cnt;
	unsigned int lmac_rx_isr_dropped_cnt;
	unsigned int rx_ctrl_mem_full;
	unsigned int rx_total_mpdu_cnt;
	unsigned int rx_mpdu_crc_fail_cnt;
	unsigned int rx_mpdu_crc_success_cnt;
	unsigned int rx_ofdm_crc_success_cnt;
	unsigned int rx_ofdm_crc_fail_cnt;
	unsigned int rx_dsss_crc_success_cnt;
	unsigned int rx_dsss_crc_fail_cnt;
	unsigned int dbg_mic_error;
	unsigned int dbg_icv_error;
	unsigned int ndpa_frame_cnt;
	unsigned int rts_cts;
	unsigned int rx_ack_cnt;
	unsigned int rx_ba_cnt;
	unsigned int rx_ack_process_cnt;
	unsigned int rx_ba_process_cnt;
	unsigned int rx_mcst_filter_fail;
	unsigned int rx_mcst_filter_success;
	unsigned int mcst_bcst_frame_for_dut;
	unsigned int rx_ucast_frame;
	unsigned int frame_not_for_dut;
	unsigned int ucast_frame_for_dut;
	unsigned int bcst_frame;
	unsigned int packets_to_host;
	unsigned int packets_dropped_in_lmac;
	unsigned int deagg_inptr_desc_empty;
	unsigned int deagg_circular_buffer_full;
	unsigned int rx_decrypt_cnt;
	unsigned int process_decrypt_fail;
	unsigned int prepa_rx_event_fail;
	unsigned int rx_bcst_frame;
	unsigned int rx_mcst_frame;
	unsigned int rx_unicast_frame;
	unsigned int unicast_addr_match;
	unsigned int unicast_addr_mismatch;
	unsigned int bcst_mcst_ours;
	unsigned int bcst_mcst_non_network_frames;
	unsigned int rx_crypto_start_cnt;
	unsigned int rx_crypto_done_cnt;
	unsigned int rx_dma_start_cnt;
	unsigned int rx_dma_done_cnt;
	unsigned int rx_hdr_dma_job_cnt;
	unsigned int rx_deadlock_cnt;
	unsigned int rx_event_buf_full;
	unsigned int rx_extram_buf_full;
	unsigned int key_not_found;
	unsigned int rx_key_found;
	unsigned int rx_packet;
	unsigned int amsdu_packet_cnt;
	unsigned int amsdu_process_fail_cnt;
	unsigned int rx_frag_packet_cnt;
	unsigned int rx_defrag_fail_cnt;
	unsigned int unexpected_cnt;
	unsigned int unexpected_cnt1;
	unsigned int rx_job_success_cnt;
	unsigned int channel_switch_announcement_cnt;
};

struct ftm_debug_stats {
	unsigned int timer_start_cnt;
	unsigned int timer_cnt;
	unsigned int ftm_initiator_cmd_cnt;
	unsigned int ftm_initiator_cmd_dropped;
	unsigned int ftm_closing_done_event;
	unsigned int beacon_captured;
	unsigned int beacon_not_captured;
	unsigned int ftm_event;
	unsigned int ftm_event_failed;
	unsigned int ftm_timer_expired;
	unsigned int ftm_initiator_cpy_params_cnt;
	unsigned int ftm_null_frm_send_success;
	unsigned int ftm_null_frm_send_fail;
	unsigned int chnl_switch_done;
	unsigned int asap_case;
	unsigned int ftm_failed_no_response;
	unsigned int initiate_ftm_burst_cnt;
	unsigned int ftmi_trigger_cmd;
	unsigned int ftm_fr_send_cmd;
	unsigned int send_ftm_frame_cnt;
	unsigned int send_ftm_frame_done_cnt;
	unsigned int trigger_ftm_burst_cnt;
	unsigned int send_initial_ftm_request_frame_fail_cnt;
	unsigned int send_initial_ftm_request_frame_done_cnt;
	unsigned int off_channel_switch_cnt;
	unsigned int return_to_working_channel_cnt;
	unsigned int done_evt_failed_cnt;
	unsigned int done_evt_ap_busy_cnt;
	unsigned int mem_error_cnt;
	unsigned int ftm_request_received_cnt;
	unsigned int ftm_request_initial_received_cnt;
	unsigned int ftm_params_decode_error_cnt;
	unsigned int ftm_request_incapable_cnt;
	unsigned int ftm_request_failed_cnt;
	unsigned int ftm_non_asap_timer_set_cnt;
	unsigned int ftm_response_frame_initial_cnt;
	unsigned int ftm_response_frame_decode_error_cnt;
	unsigned int ftm_response_frame_followup_cnt;
	unsigned int ftm_response_frame_duplicate_cnt;
	unsigned int ftm_dialog_closed_cnt;
	unsigned int scan_timer_in_ftmi;
	unsigned int scan_timer_in_ftmr;
	unsigned int scan_timer_in_scan;
	unsigned int cordic_overflow;
	unsigned int car2pol_overflow;
	unsigned int pol2car_overflow;
	unsigned int denom_zero;
	unsigned int responder_enable;
	unsigned int ftm_inv_req_cnt;
	unsigned int lci_buffer_overflow;
	unsigned int civic_buffer_overflow;
};

struct lp_rx_stats {
	unsigned int scan_rf_mode_lp_rx;
	unsigned int scan_rf_mode_hptrx;
	unsigned int rf_mode_lp_rx;
	unsigned int rf_mode_hptrx;
	unsigned int bet_isr;
	unsigned int bet_bcn_abort;
	unsigned int bet_bcn_rf_switch;
	unsigned int rf_mode_switch;
};

struct lmac_sqi_stats {
	unsigned int sqi_threshold_cmds_cnt;
	unsigned int sqi_config_cmds_cnt;
	unsigned int sqi_events_cnt;
};

enum {
	INTERVAL_15SEC = 0,
	INTERVAL_MAX,
	INTERVAL_COUNT
};

/**
 * @struct lmac_sleep_timing_stats
 * @brief Tracks wake/sleep durations, counters, and interval stats.
 *
 * - last_wake_sleep_stats[i][type]:
 *   Stores previous completed interval stats for wake/sleep.
 *   i = interval index, type = 0 (wake), 1 (sleep)
 * - cur_wake_sleep_stats[i][type]:
 *   Accumulates stats for current ongoing interval.
 * - time_stamps[i]:
 *   Timestamp marking the start of each interval tracking window.
 */
struct lmac_sleep_timing_stats {
	unsigned int index;
	unsigned int bcn_delay_after_wakeup;
	unsigned int last_one_minute_bcn_rcv_cnt;
	unsigned int last_one_second_bcn_rcv_cnt;
	unsigned int current_one_minute_bcn_rcv_cnt;
	unsigned int current_one_second_bcn_rcv_cnt;
	unsigned int wake_duration[SLEEP_DEBUG_BUFFER];
	unsigned int sleep_duration[SLEEP_DEBUG_BUFFER];
	unsigned int temp_time_stamp_minute;
	unsigned int temp_time_stamp_second;
	/* 0->15s, 2->MAX */
	double time_stamps[INTERVAL_COUNT];
	/* 0: wake, 1: sleep */
	double last_wake_sleep_stats[INTERVAL_COUNT][2];
	double cur_wake_sleep_stats[INTERVAL_COUNT][2];
};



/* Sleep Debug Params */
struct lmac_sleep_stats {
	unsigned int sleep_command_in_lmac_task;
	unsigned int sleep_disable_cnt;
	unsigned int wifi_powersave_disabled;
	unsigned int total_boot_cnt;
	unsigned int warm_boot_timer_isr;
	unsigned int try_to_enter_sleep;
	unsigned int pre_assoc_timer_cnt;
	unsigned int wait_for_bcn_expired;
	unsigned int rx_bcn_cnt;
	unsigned int wait_for_bcn_cnt;
	unsigned int wait_for_unicast_cnt;
	unsigned int wait_for_broadcast_cnt;
	unsigned int cancel_warm_boot_timer;
	unsigned int more_buffered_unicast;
	unsigned int buffered_unicast;
	unsigned int more_buffered_broadcast;
	unsigned int buffered_broadcast;
	unsigned int sleep_attempt_fail_power_save_off;
	unsigned int sleep_attempt_fail_ftm_responder_active;
	unsigned int sleep_attempt_fail_vif_non_sta;
	unsigned int sleep_attempt_fail_cmds_present;
	unsigned int scan_in_progress;
	unsigned int tx_pkt_pending;
	unsigned int host_cmds;
	unsigned int host_events;
	unsigned int rx_in_progress;
	unsigned int tx_in_progress;
	unsigned int sleep_request_failed;
	unsigned int attempt_sleep_req_cnt;
	unsigned int warm_boot_cnt;
	unsigned int wakeup_rpu_enabled;
	unsigned int wakeup_now;
	unsigned int sleep_failed;
	unsigned int cmd_ps_from_host;
	unsigned int power_save_indication_to_ap_success;
	unsigned int power_save_indication_to_ap_fail;
	unsigned int post_assoc_int_command;
	unsigned int post_assoc_check_lmac_activity_fail;
	unsigned int too_less_to_sleep;
	unsigned int sleep_time_in_us;
	unsigned int sleep_request_to_umac;
	unsigned int sleep_status_from_umac;
	unsigned int sleep_request_to_umac_failed;
	unsigned int hal_event_cnt;
	unsigned int rx_event_pending;
	unsigned int seq_nu;
	unsigned int grtc_isrcnt;
	unsigned int bb_isrcnt;
	unsigned int lp_bringup_time;
	unsigned int hp_bringup_time;
	unsigned int lp2hp_bringup_time;
};

struct lmac_twt_stats {
	unsigned int twt_isr;
	unsigned int twt_isr_start;
	unsigned int twt_isr_end;
	unsigned int basic_trigger_cnt;
	unsigned int twt_req_cnt;
	unsigned int twt_teardown_cnt;
	unsigned int twt_isr_state;
	unsigned int block_cnt;
	unsigned int unblock_cnt;
	unsigned int twt_sleep_req_to_umac;
	unsigned int twt_sleep_resp_succ;
	unsigned int twt_sleep_resp_fail;
	unsigned int boot_awake_window;
	unsigned int boot_sleep_window;
	unsigned int boot_next_twt_window;
	unsigned int isr_awake_window;
	unsigned int isr_sleep_window;
	unsigned int isr_less_sleep_window;
	unsigned int isr_next_twt_window;
	unsigned int lmac_busy;
	unsigned int isr_flush_cnt;
	unsigned int flush_cnt;
	unsigned int resync_cnt;
	unsigned int wait_for_bcn_tsf;
	unsigned int twt_less_sleep_time;
	unsigned int invalid_start_tsf1;
	unsigned int invalid_start_tsf2;
	unsigned int invalid_start_tsf3;
	unsigned int invalid_target_wake_interval;
	unsigned int ps_poll_sent;
	unsigned int debug_sleep_time;
	unsigned int time_stamp_before_sleep;
	unsigned int time_stamp_after_sleep;
};
struct lmac_offload_raw_tx_stats {
	unsigned int offLoad_raw_tx_state;
	unsigned int offload_raw_tx_cnt;
	unsigned int offload_raw_tx_complete_cnt;
	unsigned int warm_boot_cnt;
};

enum LMAC_STATS_CATEGORY {
	LMAC_STATS_INIT_DEBUG_PARAMS = (1 << 0),
	PHY_IF_DEBUG_STATS = (1 << 1),
	TX_DEBUG_PARAMS = (1 << 2),
	RX_DEBUG_PARAMS = (1 << 3),
	SCAN_DEBUG_PARAMS = (1 << 4),
	SLEEP_DEBUG_PARAMS = (1 << 5),
	WAKE_SLEEP_STATS = (1 << 6),
	TWT_DEBUG_PARAMS = (1 << 7),
	LMAC_HE_DEBUGPARAMS = (1 << 8),
	FTM_DEBUG_STATS = (1 << 9),
	LP_RX_STATS = (1 << 10),
	LMAC_SQI_STATS = (1 << 11),
	EDCA_CONFIG = (1 << 12),
	CRYPTO_CONFIG = (1 << 13),
	AGG_CONFIG = (1 << 14),
	DEAGG_CONFIG = (1 << 15),
	MAC_CTRL_CONFIG = (1 << 16),
	OFFLOAD_RAW_TX_STATS = (1 << 17),
	MAC_STATS_END = (1 << 18),
};

enum PHY_STATS_CATEGORY {
	PHY_RX_DEBUG_STATS    = (1 << 0),
	PHY_SW_DBG_STATS      = (1 << 1),
	PHY_RSSI_HIST_STATS   = (1 << 2),
	PHY_DC_RSSI_SNR_STATS = (1 << 3),
	PHY_STATS_END         = (1 << 4)
};


struct lmac_debug_stats {
	unsigned int stats_category;
	union {
		struct lmac_common_stats lmac_common_stats;
		struct phy_if_stats phy_if_stats;
		struct lmac_tx_stats tx_stats;
		struct lmac_rx_stats rx_stats;
		struct lmac_scan_stats scan_stats;
		struct lmac_sleep_stats sleep_stats;
		struct lmac_sleep_timing_stats sleep_timing_stats;
		struct lmac_twt_stats twt_stats;
		struct lmac_he_stats he_stats;
		struct ftm_debug_stats ftm_debug_stats;
		struct lp_rx_stats lp_stats;
		struct lmac_sqi_stats sqi_stats;
		unsigned int edca_config[96];
		unsigned int crypto_config[96];
		unsigned int agg_config[96];
		unsigned int deagg_config[96];
		unsigned int mac_ctrl_config[96];
		struct lmac_offload_raw_tx_stats offload_raw_tx_stats;
	};

} __NRF_WIFI_PKD;


/**
 * @brief This structure defines the LMAC debug parameters.
 *
 */
struct rpu_lmac_stats {
	/** Number of reset command counts from UMAC */
	unsigned int reset_cmd_cnt;
	/** Number of reset complete events sent to UMAC */
	unsigned int reset_complete_event_cnt;
	/** Number of events unable to generate */
	unsigned int unable_gen_event;
	/** Number of channel program commands from UMAC */
	unsigned int ch_prog_cmd_cnt;
	/** Number of channel program done events to UMAC */
	unsigned int channel_prog_done;
	/** Number of Tx commands from UMAC */
	unsigned int tx_pkt_cnt;
	/** Number of Tx done events to UMAC */
	unsigned int tx_pkt_done_cnt;
	/** Unused */
	unsigned int scan_pkt_cnt;
	/** Number of internal Tx packets */
	unsigned int internal_pkt_cnt;
	/** Number of Tx dones for internal packets */
	unsigned int internal_pkt_done_cnt;
	/** Number of acknowledgment responses */
	unsigned int ack_resp_cnt;
	/** Number of transmit timeouts */
	unsigned int tx_timeout;
	/** Number of deaggregation ISRs */
	unsigned int deagg_isr;
	/** Number of deaggregation input descriptor empties */
	unsigned int deagg_inptr_desc_empty;
	/** Number of deaggregation circular buffer full events */
	unsigned int deagg_circular_buffer_full;
	/** Number of LMAC received ISRs */
	unsigned int lmac_rxisr_cnt;
	/** Number of received packets decrypted */
	unsigned int rx_decryptcnt;
	/** Number of packet decryption failures during processing */
	unsigned int process_decrypt_fail;
	/** Number of RX event preparation failures */
	unsigned int prepa_rx_event_fail;
	/** Number of RX core pool full counts */
	unsigned int rx_core_pool_full_cnt;
	/** Number of RX MPDU CRC successes */
	unsigned int rx_mpdu_crc_success_cnt;
	/** Number of RX MPDU CRC failures */
	unsigned int rx_mpdu_crc_fail_cnt;
	/** Number of RX OFDM CRC successes */
	unsigned int rx_ofdm_crc_success_cnt;
	/** Number of RX OFDM CRC failures */
	unsigned int rx_ofdm_crc_fail_cnt;
	/** Number of RX DSSS CRC successes */
	unsigned int rxDSSSCrcSuccessCnt;
	/** Number of RX DSSS CRC failures */
	unsigned int rxDSSSCrcFailCnt;
	/** Number of RX crypto start counts */
	unsigned int rx_crypto_start_cnt;
	/** Number of RX crypto done counts */
	unsigned int rx_crypto_done_cnt;
	/** Number of RX event buffer full counts */
	unsigned int rx_event_buf_full;
	/** Number of RX external RAM buffer full counts */
	unsigned int rx_extram_buf_full;
	/** Number of scan requests receive from UMAC */
	unsigned int scan_req;
	/** Number of scan complete events sent to UMAC */
	unsigned int scan_complete;
	/** Number of scan abort requests */
	unsigned int scan_abort_req;
	/** Number of scan abort complete events */
	unsigned int scan_abort_complete;
	/** Number of internal buffer pool null counts */
	unsigned int internal_buf_pool_null;
	/** RPU hardware lockup event detection count */
	unsigned int rpu_hw_lockup_count;
	/** RPU hardware lockup recovery completed count */
	unsigned int rpu_hw_lockup_recovery_done;
	/** Number of Signal quality threshold set commands from host  */
	unsigned int SQIThresholdCmdsCnt;
	/** Number of Signal quality configuration commands from host  */
	unsigned int SQIConfigCmdsCnt;
	/** Signal Quality Indication event from lmac   */
	unsigned int SQIEventsCnt;
	/** Configured sleep type. */
	unsigned int SleepType;
	/** Number of warm boot /sleep cycles in RPU  */
	unsigned int warmBootCnt;
} __NRF_WIFI_PKD;

/**
 * @brief This structure defines the PHY (Physical Layer) debug statistics.
 *
 */
struct rpu_phy_stats {
	/** Rssi average value received from LMAC */
	signed char rssi_avg;
	/** Unused */
	unsigned char pdout_val;
	/** Number of OFDM CRC Pass packets */
	unsigned int ofdm_crc32_pass_cnt;
	/** Number of OFDM CRC Fail packets */
	unsigned int ofdm_crc32_fail_cnt;
	/** Number of DSSS CRC Pass packets */
	unsigned int dsss_crc32_pass_cnt;
	/** Number of DSSS CRC Fail packets */
	unsigned int dsss_crc32_fail_cnt;
} __NRF_WIFI_PKD;


/**
 * @brief structure for UMAC memory pool information.
 *
 */
struct pool_data_to_host {
	/** Size of the memory buffer */
	unsigned int buffer_size;
	/** Number of pool items available for the above memory buffer */
	unsigned char num_pool_items;
	/** Maximum pools allocated at any point of time */
	unsigned char items_num_max_allocated;
	/** Currently allocated pools */
	unsigned char items_num_cur_allocated;
	/** Total number of pool allocated */
	unsigned int items_num_total_allocated;
	/** Number of times this memory pool is full */
	unsigned int items_num_not_allocated;
} __NRF_WIFI_PKD;


/**
 * struct lmac_prod_stats - used to get the production mode stats
 */

/* Events */
#define MAX_RSSI_SAMPLES 10



/**
 * @struct nrf_wifi_rf_get_rx_debug_stats
 * @brief Holds debug statistics related to the RX.
 */
#define NRF_WIFI_RF_RX_PHY_DBG_STATS_LEN 40
struct nrf_wifi_rf_get_rx_debug_stats {
	unsigned char test;

	/** PHY RX debug counters */
	unsigned int phy_rx_dbg_stats[NRF_WIFI_RF_RX_PHY_DBG_STATS_LEN];
} __NRF_WIFI_PKD;

struct phy_debug_stats {
	unsigned int stats_category;
	union {
		unsigned int phy_stats[64];
	};
} __NRF_WIFI_PKD;

struct nrf_wifi_rpu_debug_stats {
	union {
		struct lmac_debug_stats lmac_stats;
		struct umac_debug_stats umac_stats;
		struct phy_debug_stats phy_stats;
	};
} __NRF_WIFI_PKD;

/**
 * @brief LMAC RX CRC debug locations for error event diagnostics.
 *
 * Firmware counters live in LMAC VPR RAM (lmacDebugParams.rxStats).
 * Hardware counters are WLAN MAC CTRL deaggregation registers.
 */
#define LMAC_DBG_RX_OFDM_CRC_SUCCESS_CNT_ADDR  0x2800354CUL
#define LMAC_DBG_RX_OFDM_CRC_FAIL_CNT_ADDR     0x28003550UL
#define LMAC_DBG_RX_DSSS_CRC_SUCCESS_CNT_ADDR  0x28003554UL
#define LMAC_DBG_RX_DSSS_CRC_FAIL_CNT_ADDR     0x28003558UL

#define ABS_PMB_WLAN_MAC_CTRL_DEAGG_CRC32PASS_CNT      0x4808E078UL
#define ABS_PMB_WLAN_MAC_CTRL_DEAGG_CRC32FAIL_CNT      0x4808E07CUL
#define ABS_PMB_WLAN_MAC_CTRL_DEAGG_DSSS_CRC32PASS_CNT 0x4808E0B8UL
#define ABS_PMB_WLAN_MAC_CTRL_DEAGG_DSSS_CRC32FAIL_CNT 0x4808E0BCUL

/**
 * @brief RF PLL status snapshot taken by the LMAC error event patch.
 *
 * The RF register WLDIG_READONLY0 (0x480210C0) is not reachable from the
 * application core, so assert_device_error_event_to_host_patch() reads it in
 * firmware on every error event and mirrors it into lmacDebugParams.rxStats
 * .unexpected_cnt, which ROM never writes. Bit 31 is not a WLDIG_READONLY0
 * field; the patch sets it so an all-zero readback can be told apart from
 * "no snapshot taken".
 *
 * Bit 6 is WLSXHP_ADPLL_PLL_LOCKED (high-power synthesiser), bit 15 is
 * WLSXLP_ADPLL_PLL_LOCKED (low-power synthesiser). Only one synthesiser runs
 * at a time, so the OR of the two is logged as well.
 */
#define LMAC_DBG_RF_PLL_STATUS_ADDR          0x2800360CUL

#define RF_PLL_STATUS_SXHP_ADPLL_LOCKED_MASK 0x00000040UL
#define RF_PLL_STATUS_SXLP_ADPLL_LOCKED_MASK 0x00008000UL
#define RF_PLL_STATUS_SNAPSHOT_VALID_MASK    0x80000000UL

/**
 * @brief ADPLL recovery counters maintained by the RF driver.
 *
 * The first four are the standalone globals that invoke_pll_recovery()
 * increments: trigger counts on every recovery attempt, fail counts when the
 * attempt ends with the PLL still unlocked. Note that the identically named
 * fields inside phy_rf_dbg_params_struct are never written by firmware and
 * always read 0, so these addresses are used instead.
 *
 * The last two are phy_rf_dbg_params_struct.*_recovery_trigger_count_at_phy_
 * open_end, bumped by rf_pll_lock_recheck() whenever adpll_lock_status()
 * reports the PLL unlocked at the end of PHY open.
 */
#define LMAC_DBG_HP_RECOVERY_FAIL_CNT_ADDR       0x28000C24UL
#define LMAC_DBG_HP_RECOVERY_TRIGGER_CNT_ADDR    0x28000C28UL
#define LMAC_DBG_LP_RECOVERY_FAIL_CNT_ADDR       0x28000C2CUL
#define LMAC_DBG_LP_RECOVERY_TRIGGER_CNT_ADDR    0x28000C30UL
#define LMAC_DBG_LP_UNLOCK_AT_PHY_OPEN_CNT_ADDR  0x28001BECUL
#define LMAC_DBG_HP_UNLOCK_AT_PHY_OPEN_CNT_ADDR  0x28001BF0UL

/**
 * @brief Beacon reception and low-power RX state, for beacon loss diagnostics.
 *
 * rf_mode is SYS_OPER_MODE_E: 0 = RX_ONLY_MODE (low power RX), 1 =
 * TRX_NORMAL_MODE. pwr_sub_state is pwrSubState: 0 = PRE_INIT,
 * 1 = WAIT_FOR_BEACON, 2 = WAIT_FOR_BEACON_FOREVER, 3 = WAIT_FOR_BCST_FRAME,
 * 4 = WAIT_FOR_UCST_FRAME, 5 = WAIT_FOR_BCST_UCST_FRAME,
 * 6 = WAIT_FOR_INACTIVITY, 7 = ATTEMPT_SLEEP_FROM_BCN,
 * 8 = WAIT_FOR_UMAC_RESPONSE, 9 = TWT_IN_PROGRESS.
 *
 * bcn_delay_after_wakeup and lp2hp_bringup_time are microsecond timings
 * measured by firmware; compare the latter against the hw_bringup_time
 * (HW_DELAY) budget sent in the init command.
 */
#define LMAC_DBG_RX_BCN_CNT_ADDR                 0x28003660UL
#define LMAC_DBG_WAIT_FOR_BCN_CNT_ADDR           0x28003664UL
#define LMAC_DBG_WAIT_FOR_BCN_EXPIRED_ADDR       0x2800365CUL
#define LMAC_DBG_LP2HP_BRINGUP_TIME_ADDR         0x28003708UL
#define LMAC_DBG_BCN_DELAY_AFTER_WAKEUP_ADDR     0x28003714UL
#define LMAC_DBG_BCN_RCV_CNT_LAST_SEC_ADDR       0x2800371CUL
#define LMAC_DBG_BCN_RCV_CNT_CUR_SEC_ADDR        0x28003724UL

#define LMAC_DBG_LP_RX_BET_ISR_ADDR              0x28003A30UL
#define LMAC_DBG_LP_RX_BET_BCN_ABORT_ADDR        0x28003A34UL
#define LMAC_DBG_LP_RX_BET_BCN_RF_SWITCH_ADDR    0x28003A38UL
#define LMAC_DBG_LP_RX_RF_MODE_SWITCH_ADDR       0x28003A3CUL

#define LMAC_DBG_CH_INFO_RF_MODE_ADDR            0x280045B8UL
#define LMAC_DBG_PWR_SUB_STATE_ADDR              0x280047C0UL

/**
 * @brief BET early-abort state.
 *
 * On a beacon with TIM clear, bssBeaconIsr() sets ABORT_RX_AFTER_LEN to 1 to
 * truncate the beacon and sets betSleepIndicationTrue. The register is only
 * restored to 0xffffff by the RX ISR (lmac_rx.c), gated on that same flag. If
 * the RX ISR does not run for the truncated frame, the register stays at 1 and
 * every subsequent frame is aborted after one byte.
 *
 * abort_rx_after_len is a 16-bit field of a 32-bit register, so it reads as
 * 0xffff when open and 0x0001 when the beacon abort is left armed.
 * betSleepIndicationTrue is a single byte.
 */
#define LMAC_DBG_BET_SLEEP_INDICATION_ADDR       0x280047C5UL
#define LMAC_DBG_BCN_MISS_CNT_ADDR               0x280046A4UL
#define LMAC_DBG_DEAGG_ISR_ADDR                  0x28003530UL
#define LMAC_DBG_LMAC_RXISR_CNT_ADDR             0x28003534UL
#define LMAC_DBG_LMAC_RX_ISR_DROPPED_CNT_ADDR    0x28003538UL

#define ABS_PMB_WLAN_MAC_CTRL_DEAGG_ABORT_RX_AFTER_LEN 0x4808E238UL
#define PMB_WLAN_MAC_CTRL_DEAGG_ABORT_RX_AFTER_LEN_MASK 0x0000FFFFUL

/**
 * @brief Sleep/wake cycling and PHY execution flow, for the interrupt stall.
 *
 * During a beacon loss episode every RF and MAC interrupt counter freezes
 * while the NWLOST timer keeps running. These distinguish "parked and not
 * waking" from "waking but not detecting beacons": total_boot_cnt and
 * warm_boot_timer_isr advance once per sleep/wake cycle.
 *
 * last_signature is the most recent PHY/RF function signature
 * (phy_function_exec_flow_enum.h) and exec_flow_ptr indexes the 64-entry ring
 * buffer at 0x28001BF4. Both are single bytes.
 *
 * pwr_main_state is pwrMainState; sleepEnable is 0 = SLEEP_DISABLE,
 * 1 = SW_SLEEP_ENABLE, 2 = HW_SLEEP_ENABLE.
 */
#define LMAC_DBG_PWR_MAIN_STATE_ADDR             0x280047BCUL
#define LMAC_DBG_SLEEP_ENABLE_ADDR               0x28004650UL
#define LMAC_DBG_BET_ENABLE_ADDR                 0x280046A0UL
#define LMAC_DBG_CFG_BET_ENABLE_ADDR             0x280047F0UL
#define LMAC_DBG_TOTAL_BOOT_CNT_ADDR             0x2800364CUL
#define LMAC_DBG_WARM_BOOT_TIMER_ISR_ADDR        0x28003650UL
#define LMAC_DBG_TRY_TO_ENTER_SLEEP_ADDR         0x28003654UL
#define LMAC_DBG_PHY_LAST_SIGNATURE_ADDR         0x28001C34UL
#define LMAC_DBG_PHY_EXEC_FLOW_PTR_ADDR          0x28001C35UL

/**
 * @brief PHY/RF execution flow ring buffer.
 *
 * phy_rf_dbg_params_struct.function_exec_flow[64]. Each entry is one function
 * signature, written as function_exec_flow[(exec_flow_ptr++) & 0x3F], so the
 * newest entry is at index ((exec_flow_ptr - 1) & 0x3F) and the buffer reads
 * oldest-first starting from exec_flow_ptr.
 */
#define LMAC_DBG_PHY_EXEC_FLOW_ADDR              0x28001BF4UL
#define LMAC_DBG_PHY_EXEC_FLOW_SIZE              64

/**
 * @brief Why a sleep attempt was refused.
 *
 * postAssocSleep() bails out on sleepEnable == SLEEP_DISABLE
 * (sleep_disable_cnt), on anyActiveStation() (wifi_powersave_disabled), or on
 * an empty internal command pool (internal_buf_pool_null); otherwise it queues
 * POST_ASSOC_SLEEP_CMD and sleep_command_in_lmac_task counts the handler
 * dequeuing it. The sleep_attempt_fail_* counters are the refusal reasons
 * inside the handler itself.
 *
 * Exactly one of these must be advancing whenever try_to_enter_sleep advances
 * while total_boot_cnt stays frozen.
 */
#define LMAC_DBG_SLEEP_CMD_IN_LMAC_TASK_ADDR     0x28003640UL
#define LMAC_DBG_SLEEP_DISABLE_CNT_ADDR          0x28003644UL
#define LMAC_DBG_WIFI_POWERSAVE_DISABLED_ADDR    0x28003648UL
#define LMAC_DBG_INTERNAL_BUF_POOL_NULL_ADDR     0x2800341CUL
#define LMAC_DBG_SLEEP_FAIL_PS_OFF_ADDR          0x28003684UL
#define LMAC_DBG_SLEEP_FAIL_FTM_RESP_ADDR        0x28003688UL
#define LMAC_DBG_SLEEP_FAIL_VIF_NON_STA_ADDR     0x2800368CUL
#define LMAC_DBG_SLEEP_FAIL_CMDS_PRESENT_ADDR    0x28003690UL

struct lmac_error_stat_entry {
	const char *name;
	unsigned int addr;
};

/**
 * @}
 */
#endif /* __NRF71_WIFI_STATS_H__ */
