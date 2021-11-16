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

namespace Phalcon\Tests\Unit\Html\Link\Link;

use Phalcon\Html\Link\Link;
use UnitTester;

/**
 * Class GetRelsCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\Link
 */
class GetRelsCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: getRels()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function linkLinkGetRels(UnitTester $I)
    {
        $I->wantToTest('Html\Link\Link - getRels()');

        $href = 'https://dev.phalcon.ld';
        $link = new Link('payment', $href);

        $expected = ['payment'];
        $I->assertEquals($expected, $link->getRels());
    }
}
