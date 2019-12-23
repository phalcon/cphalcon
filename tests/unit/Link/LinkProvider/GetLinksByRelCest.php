<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Link\LinkProvider;

use Phalcon\Link\Link;
use Phalcon\Link\LinkProvider;
use UnitTester;

class GetLinksByRelCest
{
    /**
     * Tests Phalcon\Link\LinkProvider :: getLinksByRel()
     *
     * @since  2019-06-15
     */
    public function linkLinkProviderGetLinksByRel(UnitTester $I)
    {
        $I->wantToTest('Link\LinkProvider - getLinksByRel()');

        $links = [
            new Link('canonical', 'https://dev.cardoe.ld'),
            new Link('cite-as', 'https://test.cardoe.ld'),
        ];
        $link  = new LinkProvider($links);

        $expected = [
            $links[1],
        ];

        $I->assertEquals($expected, $link->getLinksByRel('cite-as'));
        $I->assertEquals([], $link->getLinksByRel('unknown'));
    }
}
