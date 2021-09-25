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

use Phalcon\Html\Link\Serializer\Header;
use Phalcon\Html\Link\Serializer\SerializerInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Html\Link\Serializer\Header :: __construct()
     *
     * @since  2019-11-02
     */
    public function linkLinkSerializerHeaderConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Link\Serializer\Header - __construct()');

        $serializer = new Header();

        $class = SerializerInterface::class;
        $I->assertInstanceOf($class, $serializer);
    }
}
