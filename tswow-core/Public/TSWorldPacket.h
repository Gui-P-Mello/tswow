/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "TSMain.h"
#include "TSString.h"
#include "TSClasses.h"

class TC_GAME_API TSWorldPacket {
public:
    WorldPacket *packet;
    bool owner;

    TSWorldPacket();
    TSWorldPacket(uint16 opcode, uint32 res = 200);
    TSWorldPacket(WorldPacket *packet);
    TSWorldPacket* operator->() { return this;}
    operator bool() const { return packet != nullptr; }
    bool operator==(TSWorldPacket const& rhs) { return packet == rhs.packet; }

    ~TSWorldPacket();
    bool IsNull() { return packet == nullptr; }
    uint16 GetOpcode();
    uint32 GetSize();
    void SetOpcode(uint32 opcode);

    int8 ReadInt8(uint32 index);
    int8 ReadInt8();
    void WriteInt8(uint32 index, int8 value);
    void WriteInt8(int8 value);

    uint8 ReadUInt8(uint32 index);
    uint8 ReadUInt8();
    void WriteUInt8(uint32 index, uint8 value);
    void WriteUInt8(uint8 value);

    int16 ReadInt16(uint32 index);
    int16 ReadInt16();
    void WriteInt16(uint32 index, int16 value);
    void WriteInt16(int16 value);

    uint16 ReadUInt16(uint32 index);
    uint16 ReadUInt16();
    void WriteUInt16(uint32 index, uint16 value);
    void WriteUInt16(uint16 value);

    int32 ReadInt32(uint32 index);
    int32 ReadInt32();
    void WriteInt32(uint32 index, int32 value);
    void WriteInt32(int32 value);

    uint32 ReadUInt32(uint32 index);
    uint32 ReadUInt32();
    void WriteUInt32(uint32 index, uint32 value);
    void WriteUInt32(uint32 value);

    int64 ReadInt64(uint32 index);
    int64 ReadInt64();
    void WriteInt64(uint32 index, int64 value);
    void WriteInt64(int64 value);

    uint64 ReadUInt64(uint32 index);
    uint64 ReadUInt64();
    void WriteUInt64(uint32 index, uint64 value);
    void WriteUInt64(uint64 value);

    float ReadFloat(uint32 index);
    float ReadFloat();
    void WriteFloat(float value);
    void WriteFloat(uint32 index, float value);

    double ReadDouble(uint32 index);
    double ReadDouble();
    void WriteDouble(double value);
    void WriteDouble(uint32 index, double value);

    TSString ReadString();
    TSString ReadString(uint32 index);
    void WriteString(TSString value);
    void WriteString(uint32 index, TSString value);
};

namespace WorldPackets {
    namespace WorldState {
        class InitWorldStates;
    }
}
class TC_GAME_API TSWorldStatePacket
{
public:
    WorldPackets::WorldState::InitWorldStates* m_ws;
    TSWorldStatePacket(WorldPackets::WorldState::InitWorldStates* ws);
    operator bool() const { return m_ws != nullptr; }
    bool operator==(TSWorldStatePacket const& rhs) { return m_ws == rhs.m_ws; }
    void push(int32 variableId, int32 value);
    uint32 length();
    int32 GetVariable(uint32 index);
    int32 GetValue(uint32 index);
    void Remove(uint32 index);
    void Clear();
};