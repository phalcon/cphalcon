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

namespace Phalcon\Test\Unit\Html\Link\EvolvableLinkProvider;

use Phalcon\Html\Link\EvolvableLinkProvider;
use Phalcon\Html\Link\Link;
use UnitTester;

class GetLinksByRelCest
{
    /**
     * Tests Phalcon\Html\Link\EvolvableLinkProvider :: getLinksByRel()
     *
     * @since  2019-11-02
     */
    public function linkEvolvableLinkProviderGetLinksByRel(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLinkProvider - getLinksByRel()');

        $links = [
            new Link('canonical', 'https://dev.phalcon.ld'),
            new Link('cite-as', 'https://test.phalcon.ld'),
        ];
        $link  = new EvolvableLinkProvider($links);

        $expected = [
            $links[1],
        ];

        $I->assertEquals($expected, $link->getLinksByRel('cite-as'));
        $I->assertEquals([], $link->getLinksByRel('unknown'));
    }
}
