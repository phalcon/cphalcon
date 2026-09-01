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

namespace Phalcon\Tests\Unit\Support\Fake;

/**
 * Trait VersionTrait
 *
 * @package Phalcon\Tests\Fixtures\Traits
 */
trait VersionTrait
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    protected function numberToSpecial(string $number): string
    {
        $map = [
            '1' => 'alpha',
            '2' => 'beta',
            '3' => 'RC',
        ];

        return $map[$number] ?? '';
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    protected function specialToNumber(string $input): string
    {
        $map = [
            'alpha' => '1',
            'beta'  => '2',
            'RC'    => '3',
        ];

        return $map[$input] ?? '4';
    }
}
