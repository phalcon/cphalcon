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

namespace Phalcon\Tests\Unit\Queue\Adapter\Stream;

use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Queue\Adapter\Stream\StreamConnectionFactory;
use Phalcon\Tests\Unit\Queue\AbstractContextConformanceTestCase;

use function glob;
use function is_dir;
use function rmdir;
use function sys_get_temp_dir;
use function uniqid;
use function unlink;

final class StreamConformanceTest extends AbstractContextConformanceTestCase
{
    private string $storageDir = '';

    protected function setUp(): void
    {
        parent::setUp();

        $this->storageDir = sys_get_temp_dir() . '/phalcon-queue-' . uniqid('', true);
    }

    protected function tearDown(): void
    {
        if (is_dir($this->storageDir)) {
            foreach ((array) glob($this->storageDir . '/*') as $file) {
                unlink($file);
            }

            rmdir($this->storageDir);
        }

        parent::tearDown();
    }

    protected function createContext(): ContextInterface
    {
        return (new StreamConnectionFactory(['storageDir' => $this->storageDir]))
            ->createContext();
    }
}
