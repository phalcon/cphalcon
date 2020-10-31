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

namespace Phalcon\Test\Unit\Html\Link\Serializer\Header;

use Phalcon\Html\Link\EvolvableLink;
use Phalcon\Html\Link\Serializer\Header;
use UnitTester;

class SerializeCest
{
    /**
     * Tests Phalcon\Html\Link\Serializer\Header :: serialize()
     *
     * @since  2019-11-02
     */
    public function linkLinkSerializerHeaderSerialize(UnitTester $I)
    {
        $I->wantToTest('Html\Link\Serializer\Header :: serialize()');

        $serializer = new Header();

        $link     = new EvolvableLink('prefetch', '/images/apple-icon-114.png');
        $expected = '</images/apple-icon-114.png>; rel="prefetch"';
        $actual   = $serializer->serialize([$link]);
        $I->assertEquals($expected, $actual);

        $links = [
            (new EvolvableLink('preload', '/1'))
                ->withAttribute('as', 'image')
                ->withAttribute('nopush', true),
            (new EvolvableLink('alternate', '/2'))
                ->withRel('next')
                ->withAttribute('hreflang', ['en', 'es']),
        ];

        $expected = '</1>; rel="preload"; as="image"; nopush,'
            . '</2>; rel="alternate next"; hreflang="en"; hreflang="es"';
        $actual   = $serializer->serialize($links);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Link\Serializer\Header :: serialize() - empty
     *
     * @since  2019-11-02
     */
    public function linkLinkSerializerHeaderSerializeEmpty(UnitTester $I)
    {
        $I->wantToTest('Html\Link\Serializer\Header :: serialize() - empty');

        $serializer = new Header();

        $I->assertNull($serializer->serialize([]));
    }
}
