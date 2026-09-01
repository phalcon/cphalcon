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

namespace Phalcon\Tests\Unit\Annotations\Fake;

/**
 * A probe used to prove that a planted annotation-cache file cannot instantiate
 * an arbitrary class: if this class is ever unserialized, __wakeup() records it.
 */
final class AnnotationInjectionProbe
{
    public static bool $woken = false;

    public function __wakeup(): void
    {
        self::$woken = true;
    }
}
