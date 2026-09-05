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

namespace Phalcon\Tests\Unit\Messages\Fake;

use Phalcon\Messages\MessageInterface;

class FakeMessage implements MessageInterface
{
    protected int $code;

    protected string $field;
    protected string $message;

    protected array $metaData = [];

    protected string $type;

    /**
     * Phalcon\Messages\Message constructor
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

    public function getCode(): int
    {
        return $this->code;
    }

    public function getField(): string
    {
        return $this->field;
    }

    public function getMessage(): string
    {
        return $this->message;
    }

    public function getMetaData(): array
    {
        return $this->metaData;
    }

    public function getType(): string
    {
        return $this->type;
    }

    /**
     * Sets code for the message
     *
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
     * @return $this|MessageInterface
     */
    public function setType(string $type): MessageInterface
    {
        $this->type = $type;

        return $this;
    }
}
