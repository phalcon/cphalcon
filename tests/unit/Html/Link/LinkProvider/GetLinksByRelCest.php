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

namespace Phalcon\Tests\Unit\Html\Link\LinkProvider;

use Phalcon\Html\Link\Link;
use Phalcon\Html\Link\LinkProvider;
use UnitTester;

/**
 * Class GetLinksByRelCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\LinkProvider
 */
class GetLinksByRelCest
{
    /**
     * Tests Phalcon\Html\Link\LinkProvider :: getLinksByRel()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function linkLinkProviderGetLinksByRel(UnitTester $I)
    {
        $I->wantToTest('Html\Link\LinkProvider - getLinksByRel()');

        $links = [
            new Link('canonical', 'https://dev.phalcon.ld'),
            new Link('cite-as', 'https://test.phalcon.ld'),
        ];
        $link  = new LinkProvider($links);

        $expected = [
            $links[1],
        ];

        $I->assertEquals($expected, $link->getLinksByRel('cite-as'));
        $I->assertEquals([], $link->getLinksByRel('unknown'));
    }
}
