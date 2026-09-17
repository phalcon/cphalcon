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

namespace Phalcon\Tests\Support\Fake;

use Phalcon\Queue\Adapter\Beanstalk\BeanstalkConnection;

use function strlen;

/**
 * Beanstalk connection that records the commands it sends and answers with a
 * canned status, so the protocol layer runs without a server.
 */
final class FakeBeanstalkConnection extends BeanstalkConnection
{
    /**
     * @var string[]
     */
    public array $commands = [];

    /**
     * @var string[]
     */
    public array $status = [];

    public function readStatus(): array
    {
        return $this->status;
    }

    public function write(string $data): int | false
    {
        $this->commands[] = $data;

        return strlen($data);
    }
}
