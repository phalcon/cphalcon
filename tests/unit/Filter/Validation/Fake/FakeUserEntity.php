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

namespace Phalcon\Tests\Unit\Filter\Validation\Fake;

/**
 * Simple entity stub that does not extend Phalcon\Mvc\Model so tests can run
 * without a database connection.
 */
class FakeUserEntity
{
    /**
     * @var mixed
     */
    public $name;

    /**
     * @param array<string, mixed> $data
     */
    public function __construct(array $data = [])
    {
        foreach ($data as $key => $value) {
            $this->$key = $value;
        }
    }

    /**
     * @param array<string, mixed> $data
     */
    public function assign(array $data): void
    {
        foreach ($data as $key => $value) {
            $this->$key = $value;
        }
    }
}
