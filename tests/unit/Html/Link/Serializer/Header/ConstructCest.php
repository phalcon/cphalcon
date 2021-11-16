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

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\Serializer\Header
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Html\Link\Serializer\Header :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function linkLinkSerializerHeaderConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Link\Serializer\Header - __construct()');

        $serializer = new Header();

        $class = SerializerInterface::class;
        $I->assertInstanceOf($class, $serializer);
    }
}
