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

namespace Phalcon\Tests\Unit\Mvc\Model\MetaData\Stream;

use Phalcon\Mvc\Model\MetaData\Stream;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use PHPUnit\Framework\Attributes\DataProvider;

use function file_exists;
use function file_put_contents;
use function glob;

final class ReadWriteTest extends AbstractUnitTestCase
{
    /**
     * @return array<array-key, array<array-key, string>>
     */
    public static function getExamples(): array
    {
        return [
            'empty file'     => ['meta-empty', ''],
            'truncated file' => ['meta-truncated', "<?php return array ( 0 => array ( 0 => 'inv"],
            'scalar value'   => ['meta-scalar', '<?php return 1; '],
        ];
    }

    /**
     * A cache file that is empty, partially written or does not return an
     * array is a cache miss.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17608
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-24
     */
    #[DataProvider('getExamples')]
    public function testMvcModelMetaDataStreamReadInvalidFile(
        string $key,
        string $contents
    ): void {
        $dir     = Talon::settings()->outputPath('tests/cache/');
        $file    = $dir . $key . '.php';
        $adapter = new Stream(['metaDataDir' => $dir]);

        file_put_contents($file, $contents);

        $actual = $adapter->read($key);

        $this->safeDeleteFile($file);

        $this->assertNull($actual);
    }

    /**
     * "meta-A\\B" and "meta-A_B" both normalize to "meta-a_b"; the second
     * gets a hash suffix so the two never share a cache file.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcModelMetaDataStreamReadWriteNoCollision(): void
    {
        $dir     = Talon::settings()->outputPath('tests/cache/');
        $adapter = new Stream(['metaDataDir' => $dir]);

        $adapter->write('meta-A\\B', ['x' => 1]);
        $adapter->write('meta-A_B', ['x' => 2]);

        $first  = $adapter->read('meta-A\\B');
        $second = $adapter->read('meta-A_B');

        foreach (glob($dir . 'meta-a_b*.php') as $file) {
            $this->safeDeleteFile($file);
        }

        $this->assertSame(['x' => 1], $first);
        $this->assertSame(['x' => 2], $second);
    }

    /**
     * The data is written to a temporary file that is then renamed to the
     * cache file. No temporary file stays in the directory.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17608
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-24
     */
    public function testMvcModelMetaDataStreamWriteNoTemporaryFile(): void
    {
        $dir     = Talon::settings()->outputPath('tests/cache/');
        $file    = $dir . 'meta-atomic.php';
        $adapter = new Stream(['metaDataDir' => $dir]);

        $adapter->write('meta-atomic', ['x' => 1]);

        $exists    = file_exists($file);
        $actual    = $adapter->read('meta-atomic');
        $temporary = glob($file . '.tmp.*');

        $this->safeDeleteFile($file);

        $this->assertTrue($exists);
        $this->assertSame(['x' => 1], $actual);
        $this->assertSame([], $temporary);
    }
}
