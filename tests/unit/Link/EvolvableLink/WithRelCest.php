<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Link\EvolvableLink;

use Phalcon\Link\EvolvableLink;
use UnitTester;

class WithRelCest
{
    /**
     * Tests Phalcon\Link\Link :: withRel()
     *
     * @since  2019-06-15
     */
    public function linkEvolvableLinkWithRel(UnitTester $I)
    {
        $I->wantToTest('Link\EvolvableLink - withRel()');

        $href = 'https://dev.cardoe.ld';
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
