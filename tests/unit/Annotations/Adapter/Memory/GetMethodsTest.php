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

namespace Phalcon\Tests\Unit\Annotations\Adapter\Memory;

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\Collection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use TestClass;

use function array_keys;
use function dataDir;

final class GetMethodsTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function testAnnotationsAdapterMemoryGetMethods(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $adapter = new Memory();

        $methodAnnotations = $adapter->getMethods(TestClass::class);

        $expected = [
            'testMethod1',
            'testMethod3',
            'testMethod4',
            'testMethod5',
        ];
        $actual   = array_keys($methodAnnotations);
        $this->assertEquals($expected, $actual);

        foreach ($methodAnnotations as $methodAnnotation) {
            $this->assertInstanceOf(Collection::class, $methodAnnotation);
        }
    }
}
