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

use Phalcon\Queue\Adapter\Stream\StreamConnectionFactory;
use Phalcon\Tests\AbstractUnitTestCase;

use function dirname;
use function explode;
use function fclose;
use function file_put_contents;
use function function_exists;
use function glob;
use function is_dir;
use function proc_close;
use function proc_open;
use function range;
use function rmdir;
use function sort;
use function stream_get_contents;
use function sys_get_temp_dir;
use function trim;
use function uniqid;
use function unlink;
use function var_export;

use const PHP_BINARY;
use const PHP_EOL;
use const SORT_NUMERIC;

final class StreamFlockTest extends AbstractUnitTestCase
{
    private string $storageDir = '';

    protected function setUp(): void
    {
        parent::setUp();

        $this->storageDir = sys_get_temp_dir() . '/phalcon-queue-flock-' . uniqid('', true);
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

    /**
     * Produce every message up front (so the queue is static while it is
     * drained), then drain it concurrently from several worker processes.
     * flock must guarantee that each message is consumed by exactly one
     * worker - no losses, no duplicates.
     */
    public function testConcurrentConsumersDrainEachMessageExactlyOnce(): void
    {
        if (!function_exists('proc_open')) {
            $this->markTestSkipped('proc_open is not available');
        }

        $total   = 200;
        $workers = 4;

        $context  = (new StreamConnectionFactory(['storageDir' => $this->storageDir]))->createContext();
        $queue    = $context->createQueue('flock');
        $producer = $context->createProducer();

        for ($i = 0; $i < $total; $i++) {
            $producer->send($queue, $context->createMessage((string) $i));
        }

        $autoload = var_export(dirname(__DIR__, 5) . '/vendor/autoload.php', true);
        $script   = $this->storageDir . '/worker.php';

        file_put_contents(
            $script,
            '<?php require ' . $autoload . ';'
            . '$f = new \Phalcon\Queue\Adapter\Stream\StreamConnectionFactory(["storageDir" => $argv[1]]);'
            . '$c = $f->createContext();'
            . '$k = $c->createConsumer($c->createQueue("flock"));'
            . 'while (($m = $k->receiveNoWait()) !== null) { echo $m->getBody() . "\n"; }'
        );

        $procs = [];
        $pipes = [];

        for ($w = 0; $w < $workers; $w++) {
            $procs[$w] = proc_open(
                [PHP_BINARY, '-d', 'extension=ext/modules/phalcon.so', $script, $this->storageDir],
                [1 => ['pipe', 'w'], 2 => ['pipe', 'w']],
                $pipes[$w]
            );
        }

        $consumed = [];

        for ($w = 0; $w < $workers; $w++) {
            $output = (string) stream_get_contents($pipes[$w][1]);

            fclose($pipes[$w][1]);
            fclose($pipes[$w][2]);
            proc_close($procs[$w]);

            foreach (explode(PHP_EOL, trim($output)) as $line) {
                if ($line !== '') {
                    $consumed[] = (int) $line;
                }
            }
        }

        sort($consumed, SORT_NUMERIC);

        $this->assertCount($total, $consumed);
        $this->assertSame(range(0, $total - 1), $consumed);
    }
}
