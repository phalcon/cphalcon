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

namespace Phalcon\Tests\Unit\Annotations\AttributesReader;

use Phalcon\Annotations\AttributesReader;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

use function array_pop;
use function explode;
use function str_starts_with;

/**
 * resolveName() is the seam that lets a developer give the short name to the
 * attributes of their own namespace, without a copy of buildNodes().
 */
final class ResolveNameTest extends AbstractUnitTestCase
{
    public function setUp(): void
    {
        $includeFile = Talon::settings()
                            ->supportPath('assets/Annotations/TestClassAttributes.php')
        ;

        require_once $includeFile;
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-21
     */
    public function testASubclassCanShortNameItsOwnNamespace(): void
    {
        $reader = new class () extends AttributesReader {
            protected function resolveName(string $name): string
            {
                if (str_starts_with($name, 'Sample\\Other\\')) {
                    $parts = explode('\\', $name);

                    return (string) array_pop($parts);
                }

                return parent::resolveName($name);
            }
        };

        $parsing = $reader->parse('TestClassAttributes');

        $this->assertSame('Marker', $parsing['class'][1]['name']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-21
     */
    public function testASubclassKeepsThePhalconRule(): void
    {
        $reader = new class () extends AttributesReader {
            protected function resolveName(string $name): string
            {
                if (str_starts_with($name, 'Sample\\Other\\')) {
                    $parts = explode('\\', $name);

                    return (string) array_pop($parts);
                }

                return parent::resolveName($name);
            }
        };

        $parsing = $reader->parse('TestClassAttributes');

        $this->assertSame('RoutePrefix', $parsing['class'][0]['name']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-21
     */
    public function testTheDefaultKeepsTheFullNameOfAnotherNamespace(): void
    {
        $reader  = new AttributesReader();
        $parsing = $reader->parse('TestClassAttributes');

        $this->assertSame('Sample\Other\Marker', $parsing['class'][1]['name']);
    }
}
