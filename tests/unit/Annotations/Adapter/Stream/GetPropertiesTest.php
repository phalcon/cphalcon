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

namespace Phalcon\Tests\Unit\Annotations\Adapter\Stream;

use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Annotations\Collection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use TestClass;

use function array_keys;
use function dataDir;

final class GetPropertiesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAnnotationsAdapterStreamGetProperties(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $adapter = new Stream(
            [
                'annotationsDir' => Talon::settings()->outputPath('tests/annotations/'),
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

        $this->safeDeleteFile(Talon::settings()->outputPath('tests/annotations/testclass.php'));
    }
}
