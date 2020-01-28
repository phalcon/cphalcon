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

namespace Phalcon\Test\Unit\Html\Link\EvolvableLink;

use Phalcon\Html\Link\EvolvableLink;
use UnitTester;

class WithRelCest
{
    /**
     * Tests Phalcon\Html\Link\Link :: withRel()
     *
     * @since  2019-11-02
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
