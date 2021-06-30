<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Support\Version;

use Phalcon\Test\Fixtures\Traits\VersionTrait;
use Phalcon\Support\Version;
use UnitTester;

use function is_string;

class GetCest
{
    use VersionTrait;

    /**
     * Tests Phalcon\Support\Version :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportVersionGet(UnitTester $I)
    {
        $I->wantToTest('Version - get()');

        $version = (new Version())->get();

        $I->assertTrue(is_string($version));
    }

    /**
     * Tests the getId() translation to get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportVersionGetIdToGet(UnitTester $I)
    {
        $I->wantToTest('Version - getId() to get()');

        $version = new Version();
        $id      = $version->getId();

        $major     = intval($id[0]);
        $med       = intval($id[1] . $id[2]);
        $min       = intval($id[3] . $id[4]);
        $special   = $this->numberToSpecial($id[5]);
        $specialNo = ($special) ? $id[6] : '';
        $expected  = "{$major}.{$med}.{$min}";
        if (true !== empty($special)) {
            $expected .= "{$special}";
            if (true !== empty($specialNo)) {
                $expected .= "{$specialNo}";
            }
        }

        $I->assertEquals(trim($expected), $version->get());
    }
}
