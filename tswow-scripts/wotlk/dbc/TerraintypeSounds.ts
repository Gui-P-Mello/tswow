/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
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

/* tslint:disable */
import { DBCKeyCell } from '../../data/dbc/DBCCell'
import { DBCFile } from '../../data/dbc/DBCFile'
import { DBCRow } from '../../data/dbc/DBCRow'
import { int } from '../../data/primitives'
import { Relation } from '../../data/query/Relations'
import { PrimaryKey } from '../../data/table/PrimaryKey'

 /**
  * Main row definition
  * - Add column comments to the commented getters below
  * - Add file comments to DBCFiles.ts
  */
export class TerraintypeSoundsRow extends DBCRow<TerraintypeSoundsCreator,TerraintypeSoundsQuery> {
    /**
     * Primary Key
     *
     * No comment (yet!)
     */
    @PrimaryKey()
    get ID() { return new DBCKeyCell(this,this.buffer,this.offset+0)}

    /**
     * Creates a clone of this row with new primary keys.
     *
     * Cloned rows are automatically added at the end of the DBC file.
     */
    clone(ID : int, c? : TerraintypeSoundsCreator) : this {
        return this.cloneInternal([ID],c);
    }
}

/**
 * Used for object creation (Don't comment these)
 */
export type TerraintypeSoundsCreator = {
}

/**
 * Used for queries (Don't comment these)
 */
export type TerraintypeSoundsQuery = {
    ID? : Relation<int>
}

/**
 * Table definition (specifies arguments to 'add' function)
 * - Add file comments to DBCFiles.ts
 */
export class TerraintypeSoundsDBCFile extends DBCFile<
    TerraintypeSoundsCreator,
    TerraintypeSoundsQuery,
    TerraintypeSoundsRow> {
    constructor() {
        super('TerrainTypeSounds',(t,b,o)=>new TerraintypeSoundsRow(t,b,o))
    }
    /** Loads a new TerraintypeSounds.dbc from a file. */
    static read(path: string): TerraintypeSoundsDBCFile {
        return new TerraintypeSoundsDBCFile().read(path);
    }
    add(ID : int, c? : TerraintypeSoundsCreator) : TerraintypeSoundsRow {
        return this.makeRow(0).clone(ID,c)
    }
    findById(id: number) {
        return this.fastSearch(id);
    }
}