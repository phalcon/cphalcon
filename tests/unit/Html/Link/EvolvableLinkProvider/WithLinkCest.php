<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Link\EvolvableLinkProvider;

use Phalcon\Html\Link\EvolvableLinkProvider;
use Phalcon\Html\Link\Link;
use UnitTester;
use function spl_object_hash;

class WithLinkCest
{
    /**
     * Tests Phalcon\Html\Link\EvolvableLinkProvider :: withLink()
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
