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

namespace Phalcon\Tests\Fixtures\Traits;

/**
 * Trait VersionTrait
 *
 * @package Phalcon\Tests\Fixtures\Traits
 */
trait VersionTrait
{
    /**
     * Translates a number to a special version string (alpha, beta, RC)
     *
     * @param string $number
     *
     * @return string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    protected function numberToSpecial(string $number): string
    {
        $special = '';

        switch ($number) {
            case '1':
                $special = 'alpha';

                break;
            case '2':
                $special = 'beta';

                break;
            case '3':
                $special = 'RC';

                break;
        }

        return $special;
    }

    /**
     * Translates a special version (alpha, beta, RC) to a version number
     *
     * @param string $input
     *
     * @return string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    protected function specialToNumber(string $input): string
    {
        switch ($input) {
            case 'alpha':
                $special = '1';

                break;
            case 'beta':
                $special = '2';

                break;
            case 'RC':
                $special = '3';

                break;
            default:
                $special = '4';

                break;
        }

        return $special;
    }
}
