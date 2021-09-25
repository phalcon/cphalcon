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

class WithoutRelCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: withoutRel()
     *
     * @since  2019-11-02
     */
    public function linkEvolvableLinkWithoutRel(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLink - withoutRel()');

        $href = 'https://dev.phalcon.ld';
        $link = new EvolvableLink('payment', $href);

        $I->assertEquals(['payment'], $link->getRels());

        $newInstance = $link
            ->withRel('citation')
            ->withRel('canonical')
        ;

        $I->assertNotSame($link, $newInstance);

        $rels = [
            'payment',
            'citation',
            'canonical',
        ];
        $I->assertEquals($rels, $newInstance->getRels());

        $newInstance = $newInstance->withoutRel('citation');

        $rels = [
            'payment',
            'canonical',
        ];
        $I->assertEquals($rels, $newInstance->getRels());
    }
}
