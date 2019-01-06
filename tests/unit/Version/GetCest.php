<?php
declare(strict_types=1);

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

/**
 * Class GetCest
 */
class GetCest
{
    use VersionTrait;

    /**
     * Tests Phalcon\Version :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function versionGet(UnitTester $I)
    {
        $I->wantToTest('Version - get()');
        $actual = is_string(Version::get());
        $I->assertTrue($actual);
    }

    /**
     * Tests the getId() translation to get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function versionGetIdToGet(UnitTester $I)
    {
        $I->wantToTest('Version - getId() to get()');
        $id        = Version::getId();
        $major     = intval($id[0]);
        $med       = intval($id[1] . $id[2]);
        $min       = intval($id[3] . $id[4]);
        $special   = $this->numberToSpecial($id[5]);
        $specialNo = ($special) ? $id[6] : '';

        $expected = trim("{$major}.{$med}.{$min}-{$special}.{$specialNo}");
        $actual   = Version::get();
        $I->assertEquals($expected, $actual);
    }
}
