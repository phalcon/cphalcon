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

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\Reflection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use TestClass;

use function apcu_fetch;
use function strtolower;

final class ReadWriteTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAnnotationsAdapterApcuReadWrite(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $prefix  = 'nova_prefix';
        $key     = 'testwrite';
        $adapter = new Apcu(
            [
                'prefix'   => $prefix,
                'lifetime' => 3600,
            ]
        );

        $classAnnotations = $adapter->get(TestClass::class);

        $adapter->write($key, $classAnnotations);

        $newClass = $adapter->read($key);
        $this->assertInstanceOf(Reflection::class, $newClass);

        $keyApc = strtolower('_PHAN' . $prefix . $key);
        $actual = apcu_fetch($keyApc);
        $this->assertNotFalse($actual);
        $this->assertEquals($classAnnotations, $actual);
    }
}
