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
use Phalcon\Tests\AbstractUnitTestCase;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLinkLinkSerializerHeaderConstruct(): void
    {
        $serializer = new Header();

        $class = SerializerInterface::class;
        $this->assertInstanceOf($class, $serializer);
    }
}
