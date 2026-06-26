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

namespace Phalcon\Tests\Unit\Html\Link\Serializer\Header;

use Phalcon\Html\Link\EvolvableLink;
use Phalcon\Html\Link\Serializer\Header;
use Phalcon\Tests\AbstractUnitTestCase;

final class SerializeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLinkLinkSerializerHeaderSerialize(): void
    {
        $serializer = new Header();

        $link     = new EvolvableLink('prefetch', '/images/apple-icon-114.png');
        $expected = '</images/apple-icon-114.png>; rel="prefetch"';
        $actual   = $serializer->serialize([$link]);
        $this->assertSame($expected, $actual);

        $links = [
            (new EvolvableLink('preload', '/1'))
                ->withAttribute('as', 'image')
                ->withAttribute('nopush', true),
            (new EvolvableLink('alternate', '/2'))
                ->withRel('next')
                ->withAttribute('hreflang', ['en', 'es']),
            // This will be ignored because it has a template
            (new EvolvableLink('alternate', '/3/login/{username}')),
        ];

        $expected = '</1>; rel="preload"; as="image"; nopush,'
            . '</2>; rel="alternate next"; hreflang="en"; hreflang="es"';
        $actual   = $serializer->serialize($links);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLinkLinkSerializerHeaderSerializeEmpty(): void
    {
        $serializer = new Header();

        $this->assertNull($serializer->serialize([]));
    }
}
