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

namespace Phalcon\Test\Fixtures\Storage\Serializer;

use Phalcon\Storage\Serializer\AbstractSerializer;
use function is_string;
use function str_rot13;

class Rot13 extends AbstractSerializer
{
    /**
     * Serializes data
     */
    public function serialize(): string
    {
        if (!is_string($this->data)) {
            throw new \InvalidArgumentException("Data for the serializer must of type string");
        }

        return str_rot13($this->data);
    }

    /**
     * Unserializes data
     */
    public function unserialize($data)
    {
        if (!is_string($this->data)) {
            throw new \InvalidArgumentException("Data for the unserializer must of type string");
        }

        $this->data = str_rot13($data);
    }
}
