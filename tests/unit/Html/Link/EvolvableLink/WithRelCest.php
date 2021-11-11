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
 * Class WithRelCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\EvolvableLink
 */
class WithRelCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: withRel()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function linkEvolvableLinkWithRel(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLink - withRel()');

        $href = 'https://dev.phalcon.ld';
        $link = new EvolvableLink('payment', $href);

        $I->assertEquals(['payment'], $link->getRels());

        $newInstance = $link->withRel('citation');

        $I->assertNotSame($link, $newInstance);

        $rels = [
            'payment',
            'citation',
        ];
        $I->assertEquals($rels, $newInstance->getRels());
    }
}
