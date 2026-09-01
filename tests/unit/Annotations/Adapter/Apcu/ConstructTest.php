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

namespace Phalcon\Tests\Unit\Annotations\Adapter\Apcu;

use Phalcon\Annotations\Adapter\AdapterInterface;
use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function testAnnotationsAdapterApcuConstruct(): void
    {
        $adapter = new Apcu(
            [
                'prefix'   => 'nova_prefix',
                'lifetime' => 3600,
            ]
        );

        $this->assertInstanceOf(AdapterInterface::class, $adapter);
    }
}
