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

namespace Phalcon\Tests\Fixtures\Messages;

use Phalcon\Messages\MessageInterface;

class MessageFixture implements MessageInterface
{
    /**
     * @var string
     */
    protected string $message;

    /**
     * @var string
     */
    protected string $field;

    /**
     * @var string
     */
    protected string $type;

    /**
     * @var int
     */
    protected int $code;

    /**
     * @var array
     */
    protected array $metaData = [];

    /**
     * Phalcon\Messages\Message constructor
     *
     * @param string $message
     * @param string $field
     * @param string $type
     * @param int    $code
     * @param array  $metaData
     */
    public function __construct(
        string $message,
        string $field = "",
        string $type = "",
        int $code = 0,
        array $metaData = []
    ) {
        $this->message  = $message;
        $this->field    = $field;
        $this->type     = $type;
        $this->code     = $code;
        $this->metaData = $metaData;
    }

    /**
     * Magic __toString method returns verbose message
     */
    public function __toString(): string
    {
        return $this->message;
    }

    /**
     * @return int
     */
    public function getCode(): int
    {
        return $this->code;
    }

    /**
     * @return string
     */
    public function getField(): string
    {
        return $this->field;
    }

    /**
     * @return string
     */
    public function getMessage(): string
    {
        return $this->message;
    }

    /**
     * @return array
     */
    public function getMetaData(): array
    {
        return $this->metaData;
    }

    /**
     * @return string
     */
    public function getType(): string
    {
        return $this->type;
    }

    /**
     * Sets code for the message
     *
     * @param int $code
     * @return $this|MessageInterface
     */
    public function setCode(int $code): MessageInterface
    {
        $this->code = $code;

        return $this;
    }

    /**
     * Sets field name related to message
     *
     * @param string $field
     * @return $this|MessageInterface
     */
    public function setField(string $field): MessageInterface
    {
        $this->field = $field;

        return $this;
    }

    /**
     * Sets verbose message
     *
     * @param string $message
     * @return $this|MessageInterface
     */
    public function setMessage(string $message): MessageInterface
    {
        $this->message = $message;

        return $this;
    }

    /**
     * Sets message metadata
     *
     * @param array $metaData
     * @return $this|MessageInterface
     */
    public function setMetaData(array $metaData): MessageInterface
    {
        $this->metaData = $metaData;

        return $this;
    }

    /**
     * Sets message type
     *
     * @param string $type
     * @return $this|MessageInterface
     */
    public function setType(string $type): MessageInterface
    {
        $this->type = $type;

        return $this;
    }
}
