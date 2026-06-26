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
use Phalcon\Tests\AbstractUnitTestCase;

use function spl_object_hash;

final class WithLinkTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLinkEvolvableLinkProviderWithLink(): void
    {
        $links    = [
            new Link('canonical', 'https://dev.phalcon.ld'),
        ];
        $instance = new EvolvableLinkProvider($links);

        $link        = new Link('cite-as', 'https://test.phalcon.ld');
        $newInstance = $instance->withLink($link);

        $this->assertNotSame($instance, $newInstance);

        $expected = [
            spl_object_hash($links[0]) => $links[0],
            spl_object_hash($link)     => $link,
        ];

        $this->assertSame($expected, $newInstance->getLinks());
    }
}
