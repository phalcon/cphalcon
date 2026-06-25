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

namespace Phalcon\Tests\Unit\Encryption\Fake\Crypt;

use Phalcon\Encryption\Crypt;

class FakeCryptOpensslCipherIvLength extends Crypt
{
    private int $usage = 0;

    /**
     * @param string $cipher
     *
     * @return false|int
     *
     * @link https://www.php.net/manual/en/function.openssl-cipher-iv-length
     */
    public function phpOpensslCipherIvLength(string $cipher): false|int
    {
        /**
         * Need to run this twice, and the second time it has to return false.
         */
        if (0 === $this->usage) {
            $this->usage++;

            return parent::phpOpensslCipherIvLength($cipher);
        }

        return false;
    }
}
