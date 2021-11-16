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

namespace Phalcon\Tests\Unit\Html\Link\EvolvableLink;

use Phalcon\Html\Link\EvolvableLink;
use UnitTester;

/**
 * Class GetRelsCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\EvolvableLink
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
    public function linkEvolvableLinkGetRels(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLink - getRels()');

        $href = 'https://dev.phalcon.ld';
        $link = new EvolvableLink('payment', $href);

        $expected = ['payment'];
        $I->assertEquals($expected, $link->getRels());
    }
}
