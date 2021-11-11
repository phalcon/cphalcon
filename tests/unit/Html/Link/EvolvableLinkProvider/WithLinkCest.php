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

namespace Phalcon\Tests\Unit\Html\Link\EvolvableLinkProvider;

use Phalcon\Html\Link\EvolvableLinkProvider;
use Phalcon\Html\Link\Link;
use UnitTester;

use function spl_object_hash;

/**
 * Class WithLinkCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\EvolvableLinkProvider
 */
class WithLinkCest
{
    /**
     * Tests Phalcon\Html\Link\EvolvableLinkProvider :: withLink()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function linkEvolvableLinkProviderWithLink(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLinkProvider - withLink()');

        $links    = [
            new Link('canonical', 'https://dev.phalcon.ld'),
        ];
        $instance = new EvolvableLinkProvider($links);

        $link        = new Link('cite-as', 'https://test.phalcon.ld');
        $newInstance = $instance->withLink($link);

        $I->assertNotSame($instance, $newInstance);

        $expected = [
            spl_object_hash($links[0]) => $links[0],
            spl_object_hash($link)     => $link,
        ];

        $I->assertEquals($expected, $newInstance->getLinks());
    }
}
