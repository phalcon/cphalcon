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

use function spl_object_hash;

class GetLinksCest
{
    /**
     * Tests Phalcon\Link\LinkProvider :: getLinks()
     *
     * @since  2019-06-15
     */
    public function linkLinkProviderGetLinks(UnitTester $I)
    {
        $I->wantToTest('Link\LinkProvider - getLinks()');

        $links = [
            new Link('canonical', 'https://dev.cardoe.ld'),
            new Link('cite-as', 'https://test.cardoe.ld'),
        ];
        $link  = new LinkProvider($links);

        $expected = [
            spl_object_hash($links[0]) => $links[0],
            spl_object_hash($links[1]) => $links[1],
        ];

        $I->assertEquals($expected, $link->getLinks());
    }
}
