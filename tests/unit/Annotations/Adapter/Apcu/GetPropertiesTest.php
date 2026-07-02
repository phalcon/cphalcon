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
use Phalcon\Annotations\Collection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use TestClass;

use function array_keys;
use function dataDir;

final class GetPropertiesTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function testAnnotationsAdapterApcuGetProperties(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $adapter = new Apcu(
            [
                'prefix'   => 'nova_prefix',
                'lifetime' => 3600,
            ]
        );

        $propertyAnnotations = $adapter->getProperties(TestClass::class);

        $expected = [
            'testProp1',
            'testProp3',
            'testProp4',
        ];
        $actual   = array_keys($propertyAnnotations);
        $this->assertEquals($expected, $actual);

        foreach ($propertyAnnotations as $propertyAnnotation) {
            $this->assertInstanceOf(Collection::class, $propertyAnnotation);
        }
    }
}
