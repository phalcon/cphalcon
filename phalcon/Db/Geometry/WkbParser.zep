
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Geometry;

use Phalcon\Db\Exceptions\InvalidWkb;

/**
 * Decodes a spatial column value into a geometry value object.
 *
 * Handles MySQL's internal format (4-byte little-endian SRID prefix followed
 * by standard OGC WKB) and PostGIS EWKB returned as a hex string. 2D only:
 * any Z/M ordinates are read past and discarded.
 */
class WkbParser
{
    /**
     * @var string
     */
    protected buffer = "";
    /**
     * @var int
     */
    protected length = 0;
    /**
     * @var int
     */
    protected position = 0;

    public function parse(string raw) -> <GeometryInterface>
    {
        var srid = 0, body, arr;

        if raw === "" {
            throw new InvalidWkb("empty value");
        }

        /**
         * PostGIS returns EWKB as an even-length ASCII-hex string; MySQL
         * returns binary (4-byte LE SRID prefix + standard WKB). Real binary
         * WKB is not valid ASCII hex (it carries the 0x01 byte-order byte and
         * arbitrary double bytes), so this distinguishes the two.
         */
        if strlen(raw) % 2 === 0 && ctype_xdigit(raw) {
            let body = hex2bin(raw);
        } else {
            if strlen(raw) < 5 {
                throw new InvalidWkb("buffer too short for MySQL prefix");
            }

            let arr  = unpack("V", substr(raw, 0, 4)),
                srid = (int) arr[1],
                body = substr(raw, 4);
        }

        let this->buffer   = body,
            this->length   = strlen(body),
            this->position = 0;

        return this->readGeometry(srid);
    }

    protected function readGeometry(int outerSrid) -> <GeometryInterface>
    {
        var byteOrder, little, typeWord, geomCode, baseType, hasZ, hasM,
            srid, count, i, items;

        let byteOrder = this->readByte(),
            little    = (byteOrder === 1),
            typeWord  = this->readUint32(little);

        let hasZ     = (typeWord & 0x80000000) != 0,
            hasM     = (typeWord & 0x40000000) != 0,
            srid     = outerSrid,
            geomCode = typeWord & 0x0FFFFFFF;

        if (typeWord & 0x20000000) != 0 {
            let srid = this->readUint32(little);
        }

        // ISO WKB encodes Z/M as +1000/+2000/+3000 on the type code
        if geomCode >= 3000 {
            let hasZ = true, hasM = true, baseType = geomCode - 3000;
        } elseif geomCode >= 2000 {
            let hasM = true, baseType = geomCode - 2000;
        } elseif geomCode >= 1000 {
            let hasZ = true, baseType = geomCode - 1000;
        } else {
            let baseType = geomCode;
        }

        switch baseType {
            case 1:
                return this->readPoint(little, hasZ, hasM, srid);

            case 2:
                return new LineString(this->readPointList(little, hasZ, hasM), srid);

            case 3:
                return new Polygon(this->readRingList(little, hasZ, hasM), srid);

            case 4:
            case 5:
            case 6:
            case 7:
                let count = this->readUint32(little),
                    items = [],
                    i     = 0;

                while i < count {
                    let items[] = this->readGeometry(srid),
                        i       = i + 1;
                }

                if baseType === 4 {
                    return new MultiPoint(items, srid);
                }

                if baseType === 5 {
                    return new MultiLineString(items, srid);
                }

                if baseType === 6 {
                    return new MultiPolygon(items, srid);
                }

                return new GeometryCollection(items, srid);

            default:
                throw new InvalidWkb("unknown geometry type " . baseType);
        }
    }

    protected function readPoint(bool little, bool hasZ, bool hasM, int srid) -> <Point>
    {
        var x, y;

        let x = this->readDouble(little),
            y = this->readDouble(little);

        this->skipExtraOrdinates(little, hasZ, hasM);

        return new Point(x, y, srid);
    }

    protected function readPointList(bool little, bool hasZ, bool hasM) -> array
    {
        var count, i, x, y, points = [];

        let count = this->readUint32(little),
            i     = 0;

        while i < count {
            let x = this->readDouble(little),
                y = this->readDouble(little);

            this->skipExtraOrdinates(little, hasZ, hasM);

            let points[] = new Point(x, y),
                i        = i + 1;
        }

        return points;
    }

    protected function readRingList(bool little, bool hasZ, bool hasM) -> array
    {
        var count, i, rings = [];

        let count = this->readUint32(little),
            i     = 0;

        while i < count {
            let rings[] = this->readPointList(little, hasZ, hasM),
                i       = i + 1;
        }

        return rings;
    }

    protected function skipExtraOrdinates(bool little, bool hasZ, bool hasM) -> void
    {
        if hasZ {
            this->readDouble(little);
        }

        if hasM {
            this->readDouble(little);
        }
    }

    protected function readByte() -> int
    {
        var arr;

        if this->position + 1 > this->length {
            throw new InvalidWkb("truncated buffer");
        }

        let arr = unpack("C", substr(this->buffer, this->position, 1)),
            this->position = this->position + 1;

        return (int) arr[1];
    }

    protected function readUint32(bool little) -> int
    {
        var fmt, arr;

        if this->position + 4 > this->length {
            throw new InvalidWkb("truncated buffer");
        }

        let fmt = little ? "V" : "N",
            arr = unpack(fmt, substr(this->buffer, this->position, 4)),
            this->position = this->position + 4;

        return (int) arr[1];
    }

    protected function readDouble(bool little) -> float
    {
        var fmt, arr;

        if this->position + 8 > this->length {
            throw new InvalidWkb("truncated buffer");
        }

        let fmt = little ? "e" : "E",
            arr = unpack(fmt, substr(this->buffer, this->position, 8)),
            this->position = this->position + 8;

        return (float) arr[1];
    }
}
