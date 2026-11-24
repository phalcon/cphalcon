<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Annotations\Adapter\Stream;

use ArrayObject;
use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Annotations\Reflection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use PHPUnit\Framework\Attributes\DataProvider;
use TestClass;

use function file_put_contents;
use function is_dir;
use function mkdir;
use function serialize;

final class ReadNotReflectionTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{mixed}>
     */
    public static function getExamples(): array
    {
        return [
            'array'        => [['one', 'two']],
            'int'          => [42],
            'null'         => [null],
            'other object' => [new ArrayObject()],
            'string'       => ['text'],
        ];
    }

    /**
     * A cache file that does not hold a Reflection object is a miss: get()
     * parses the class again and writes a new cache file.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17773
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-24
     */
    public function testAnnotationsAdapterStreamGetParsesAgainWhenCacheIsNotReflection(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $dir = Talon::settings()->outputPath('tests/annotations/');
        if (!is_dir($dir)) {
            mkdir($dir, 0777, true);
        }

        $path = $dir . 'testclass.php';
        file_put_contents($path, serialize(['one', 'two']));

        $adapter = new Stream(['annotationsDir' => $dir]);

        $this->assertInstanceOf(Reflection::class, $adapter->get(TestClass::class));
        $this->assertInstanceOf(Reflection::class, $adapter->read(TestClass::class));

        $this->safeDeleteFile($path);
    }

    /**
     * A cache file that does not hold a Reflection object is a miss, the
     * same as a missing file.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17773
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-24
     */
    #[DataProvider('getExamples')]
    public function testAnnotationsAdapterStreamReadNotReflection(mixed $value): void
    {
        $dir = Talon::settings()->outputPath('tests/annotations/');
        if (!is_dir($dir)) {
            mkdir($dir, 0777, true);
        }

        $path = $dir . 'notreflection.php';
        file_put_contents($path, serialize($value));

        $adapter = new Stream(['annotationsDir' => $dir]);

        $this->assertFalse($adapter->read('notreflection'));

        $this->safeDeleteFile($path);
    }
}
