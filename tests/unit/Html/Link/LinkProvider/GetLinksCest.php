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

namespace Phalcon\Test\Unit\Html\Link\LinkProvider;

use Phalcon\Html\Link\Link;
use Phalcon\Html\Link\LinkProvider;
use UnitTester;

use function spl_object_hash;

class GetLinksCest
{
    /**
     * Tests Phalcon\Html\Link\LinkProvider :: getLinks()
     *
     * @since  2019-11-02
     */
    public function linkLinkProviderGetLinks(UnitTester $I)
    {
        $I->wantToTest('Html\Link\LinkProvider - getLinks()');

        $links = [
            new Link('canonical', 'https://dev.phalcon.ld'),
            new Link('cite-as', 'https://test.phalcon.ld'),
        ];
        $link  = new LinkProvider($links);

        $expected = [
            spl_object_hash($links[0]) => $links[0],
            spl_object_hash($links[1]) => $links[1],
        ];

        $I->assertEquals($expected, $link->getLinks());
    }
}
