<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Version;

use Phalcon\Test\Fixtures\Traits\VersionTrait;
use Phalcon\Version;
use UnitTester;

class GetIdCest
{
    use VersionTrait;

    /**
     * Tests Phalcon\Version :: getId()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function versionGetId(UnitTester $I)
    {
        $I->wantToTest('Version - getId()');
        $actual = is_string(Version::getId());
        $I->assertTrue($actual);
    }

    /**
     * Tests the get() translation to getId()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function versionGetToGetId(UnitTester $I)
    {
        $I->wantToTest('Version - get() to getId()');
        $version = Version::get();
        $chunks  = explode(' ', $version);

        $special   = '4';
        $specialNo = '0';

        // There are special versions
        if (count($chunks) > 1) {
            $specialNo = $chunks[2];
            $special   = $this->specialToNumber($chunks[1]);
        }

        // Now the version itself
        $verChunks = explode('.', $chunks[0]);
        $major     = intval($verChunks[0]);
        $med       = substr("00" . intval($verChunks[1]), -2);
        $min       = substr("00" . intval($verChunks[2]), -2);

        $expected = "{$major}{$med}{$min}{$special}{$specialNo}";
        $actual   = Version::getId();
        $I->assertEquals($expected, $actual);
    }
}
