<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Link\EvolvableLinkProvider;

use Phalcon\Link\EvolvableLinkProvider;
use Phalcon\Link\Link;
use UnitTester;

use function spl_object_hash;

class WithLinkCest
{
    /**
     * Tests Phalcon\Link\EvolvableLinkProvider :: withLink()
     *
     * @since  2019-06-15
     */
    public function linkEvolvableLinkProviderWithLink(UnitTester $I)
    {
        $I->wantToTest('Link\EvolvableLinkProvider - withLink()');

        $links    = [
            new Link('canonical', 'https://dev.cardoe.ld'),
        ];
        $instance = new EvolvableLinkProvider($links);

        $link        = new Link('cite-as', 'https://test.cardoe.ld');
        $newInstance = $instance->withLink($link);

        $I->assertNotSame($instance, $newInstance);

        $expected = [
            spl_object_hash($links[0]) => $links[0],
            spl_object_hash($link)     => $link,
        ];

        $I->assertEquals($expected, $newInstance->getLinks());
    }
}
