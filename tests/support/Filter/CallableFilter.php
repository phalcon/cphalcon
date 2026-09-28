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

namespace Phalcon\Tests\Support\Filter;

use Phalcon\Filter\Filter;

/**
 * Registers array callables as sanitizers
 */
final class CallableFilter extends Filter
{
    public function __construct()
    {
        parent::__construct();

        $this->set('prefix', [$this, 'prefix']);
        $this->set('suffix', [self::class, 'suffix']);
        $this->set('wrap', [$this, 'wrap']);
    }

    public static function suffix(mixed $value): string
    {
        return $value . ':done';
    }

    public function prefix(mixed $value): string
    {
        return 'ok:' . $value;
    }

    public function wrap(mixed $value, string $left, string $right): string
    {
        return $left . $value . $right;
    }
}
