/*
 * Copyright (C) 2016 Felix Fietkau <nbd@nbd.name>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __MT7603_MCU_H
#define __MT7603_MCU_H

struct mt7603_mcu_txd {
	__le16 len;
	__le16 pq_id;

	u8 cid;
	u8 pkt_type;
	u8 set_query;
	u8 seq;

	u8 uc_d2b0_rev;
	u8 ext_cid;
	u8 uc_d2b2_rev;
	u8 ext_cid_ack;

	u32 au4_d3_to_d7_rev[5];
} __packed __aligned(4);

struct mt7603_mcu_rxd {
	__le16 len;
	__le16 pkt_type_id;

	u8 eid;
	u8 seq;
	__le16 __rsv;

	u8 ext_eid;
	u8 __rsv1[3];
};

#define MCU_PKT_ID		0xa0
#define MCU_PORT_QUEUE		0x8000
#define MCU_PORT_QUEUE_FW	0xc000

#define MCU_FIRMWARE_ADDRESS	0x100000

enum {
	MCU_Q_QUERY,
	MCU_Q_SET,
	MCU_Q_RESERVED,
	MCU_Q_NA
};

enum {
	MCU_CMD_TARGET_ADDRESS_LEN_REQ = 0x01,
	MCU_CMD_FW_START_REQ = 0x02,
	MCU_CMD_INIT_ACCESS_REG = 0x3,
	MCU_CMD_PATCH_START_REQ = 0x05,
	MCU_CMD_PATCH_FINISH_REQ = 0x07,
	MCU_CMD_PATCH_SEM_CONTROL = 0x10,
	MCU_CMD_HIF_LOOPBACK = 0x20,
	MCU_CMD_CH_PRIVILEGE = 0x20,
	MCU_CMD_ACCESS_REG = 0xC2,
	MCU_CMD_EXT_CID = 0xED,
	MCU_CMD_FW_SCATTER = 0xEE,
	MCU_CMD_RESTART_DL_REQ = 0xEF,
};

enum {
	MCU_EXT_CMD_RF_REG_ACCESS = 0x02,
	MCU_EXT_CMD_RF_TEST = 0x04,
	MCU_EXT_CMD_RADIO_ON_OFF_CTRL = 0x05,
	MCU_EXT_CMD_WIFI_RX_DISABLE = 0x06,
	MCU_EXT_CMD_PM_STATE_CTRL = 0x07,
	MCU_EXT_CMD_CHANNEL_SWITCH = 0x08,
	MCU_EXT_CMD_NIC_CAPABILITY = 0x09,
	MCU_EXT_CMD_PWR_SAVING = 0x0A,
	MCU_EXT_CMD_MULTIPLE_REG_ACCESS = 0x0E,
	MCU_EXT_CMD_AP_PWR_SAVING_CAPABILITY = 0xF,
	MCU_EXT_CMD_SEC_ADDREMOVE_KEY = 0x10,
	MCU_EXT_CMD_SET_TX_POWER_CTRL=0x11,
	MCU_EXT_CMD_FW_LOG_2_HOST = 0x13,
	MCU_EXT_CMD_PS_RETRIEVE_START = 0x14,
	MCU_EXT_CMD_LED_CTRL=0x17,
	MCU_EXT_CMD_PACKET_FILTER = 0x18,
	MCU_EXT_CMD_PWR_MGT_BIT_WIFI = 0x1B,
	MCU_EXT_CMD_EFUSE_BUFFER_MODE = 0x21,
	MCU_EXT_CMD_THERMAL_PROTECT = 0x23,
	MCU_EXT_CMD_EDCA_SET = 0x27,
	MCU_EXT_CMD_SLOT_TIME_SET = 0x28,
	MCU_EXT_CMD_CONFIG_INTERNAL_SETTING = 0x29,
	MCU_EXT_CMD_NOA_OFFLOAD_CTRL = 0x2B,
	MCU_EXT_CMD_GET_THEMAL_SENSOR=0x2C,
	MCU_EXT_CMD_WAKEUP_OPTION = 0x2E,
	MCU_EXT_CMD_AC_QUEUE_CONTROL = 0x31,
	MCU_EXT_CMD_BCN_UPDATE = 0x33
};

enum {
	MCU_EXT_EVENT_CMD_RESULT = 0x0,
	MCU_EXT_EVENT_RF_REG_ACCESS = 0x2,
	MCU_EXT_EVENT_MULTI_CR_ACCESS = 0x0E,
	MCU_EXT_EVENT_FW_LOG_2_HOST = 0x13,
	MCU_EXT_EVENT_BEACON_LOSS = 0x1A,
	MCU_EXT_EVENT_THERMAL_PROTECT = 0x22,
	MCU_EXT_EVENT_BCN_UPDATE = 0x31,
};

#endif
