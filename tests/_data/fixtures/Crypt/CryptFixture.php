<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Fixtures\Crypt;

use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Crypt\Exception\Exception;

class CryptFixture extends Crypt
{
    /**
     * Makes this method public
     *
     * @param string $input
     * @param string $mode
     * @param int    $blockSize
     * @param int    $paddingType
     *
     * @return string
     * @throws Exception
     */
    public function cryptPadText(
        string $input,
        string $mode,
        int $blockSize,
        int $paddingType
    ): string {
        return parent::cryptPadText($input, $mode, $blockSize, $paddingType);
    }

    /**
     * @param string $input
     * @param string $mode
     * @param int    $blockSize
     * @param int    $paddingType
     *
     * @return string
     * @throws Exception
     */
    public function cryptUnpadText(
        string $input,
        string $mode,
        int $blockSize,
        int $paddingType
    ): string {
        return parent::cryptUnpadText($input, $mode, $blockSize, $paddingType);
    }
}