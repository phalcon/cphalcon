<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

/**
 * Trait VersionTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
trait VersionTrait
{
    /**
     * Translates a number to a special version string (alpha, beta, RC)
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @param string $number
     *
     * @return string
     */
    protected function numberToSpecial($number): string
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @param string $input
     *
     * @return string
     */
    protected function specialToNumber($input): string
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
