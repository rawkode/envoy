#pragma once

#include <memory>
#include <string>

#include "envoy/common/time.h"
#include "envoy/event/dispatcher.h"
#include "envoy/filesystem/filesystem.h"
#include "envoy/stats/store.h"
#include "envoy/thread/thread.h"

namespace Envoy {
namespace Api {

/**
 * "Public" API that different components use to interact with the various system abstractions.
 */
class Api {
public:
  virtual ~Api() {}

  /**
   * Allocate a dispatcher.
   * @return Event::DispatcherPtr which is owned by the caller.
   */
  virtual Event::DispatcherPtr allocateDispatcher() PURE;

  /**
   * Allocate a dispatcher.
   * @param watermark_factory the watermark factory, ownership is transferred to the dispatcher.
   * @return Event::DispatcherPtr which is owned by the caller.
   */
  virtual Event::DispatcherPtr
  allocateDispatcher(Buffer::WatermarkFactoryPtr&& watermark_factory) PURE;

  /**
   * @return a reference to the ThreadFactory
   */
  virtual Thread::ThreadFactory& threadFactory() PURE;

  /**
   * @return a reference to the Filesystem::Instance
   */
  virtual Filesystem::Instance& fileSystem() PURE;

  /**
   * @return a reference to the TimeSource
   */
  virtual TimeSource& timeSource() PURE;
};

typedef std::unique_ptr<Api> ApiPtr;

} // namespace Api
} // namespace Envoy
