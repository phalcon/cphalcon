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

use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Queue\Fake\FakeStreamContextIsDir;

use function error_clear_last;
use function error_get_last;

final class StreamContextMkdirRaceTest extends AbstractUnitTestCase
{
    /**
     * FakeStreamContextIsDir always reports that the storage directory is
     * absent. The mkdir() call that follows the first pushMessage() thus finds
     * the directory on the disk and fails with "File exists" - the same result
     * as a different process that makes the directory first. The context must
     * ignore that condition: the message goes to the queue, no warning comes
     * out and no error stays behind.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-04
     */
    public function testQueueAdapterStreamPushMessageIgnoresConcurrentDirectoryCreation(): void
    {
        $storageDir = Talon::settings()->outputPath('queue-mkdir-race');
        $context    = new FakeStreamContextIsDir($storageDir);

        $context->pushMessage('race', $context->createMessage('one'));

        error_clear_last();
        $context->pushMessage('race', $context->createMessage('two'));
        $lastError = error_get_last();

        $first  = $context->popMessage('race');
        $second = $context->popMessage('race');

        $this->safeDeleteDirectory($storageDir);

        $this->assertNull($lastError);
        $this->assertNotNull($first);
        $this->assertNotNull($second);
        $this->assertSame('one', $first->getBody());
        $this->assertSame('two', $second->getBody());
    }
}
