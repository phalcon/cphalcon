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

namespace Phalcon\Tests\Support\Traits;

use function restore_error_handler;
use function set_error_handler;

trait ErrorHandlerTrait
{
    /**
     * Calls the callable and returns its result and the message of each
     * error (warning, notice) that it gives. The errors do not go to PHPUnit.
     *
     * @return array{0: mixed, 1: array<int, string>}
     */
    private function collectErrors(callable $callable): array
    {
        $messages = [];

        set_error_handler(
            static function (int $level, string $message) use (&$messages): bool {
                $messages[] = $message;

                return true;
            }
        );

        try {
            $result = $callable();
        } finally {
            restore_error_handler();
        }

        return [$result, $messages];
    }
}
