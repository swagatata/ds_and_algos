/**
 * state transition
 * 1. init
 * 2. polling
 * 3. processing
 * 4. exception handling
 *  4.1. retry n times, maybe with exponential backoff
 *  4.2. push to request queue for later processing
 */

class BackendService {
public:
  Link createEventLink(ELURequest& request) {
    // basic schema _ domain _ path
    // auth token - 
    auto& auth_token = Cognito.getAuthToken({
      user_id: request->user_id,
      });
    auto link = RegisterEventLink(auth_token, event_id);
    return link;
  }

  void sendEventLinkToUser(ELURequest request) {
    // create event link
    auto& event_link = await Backend.createEventLink({
      event_id: request->event_id,
      user_id : request->user_id,
      });
    auto& content; //
    content.append(hello_text);
    content.append(event_link);

    EmailService.sendEmail({
      to: user_id,
      subject : "Event Link",
      content : content,
      });
  }

};

class RegistrationService {
  RequestQueue requestQueue;
  int requestsPerThread;

  typedef shared_ptr<Request> req;
public:
  RegistrationService() {
    // TODO Auto-generated constructor stub

  }

  void state_machine() {
    auto& requests = poll_requests();
    // concurrently process requests
    // if exception, retry n times, maybe with exponential backoff
    try {
      auto& requestStates = await wait_for_all(requests.begin(), requests.end(), process_request);
      // iterate and identify failed requests
      for (auto& requestState : requestStates) {
        if (requestState->status == RequestStatus::FAILED) {
          // create a new request          
          auto& request = find(requests, requestState->request_id);
          handle_failed_request(request, requestState);

        }
      }
    }
    catch (Exception e) {
      // analyse exception. find if it's a system exception or a business exception
      // if system exception, retry n times, maybe with exponential backoff
      if (e.isSystemException()) {
        // retry
        // push to request queue for later processing
        for (auto& request : requests) {
          request.updateStatus(RequestStatus::FAILED);
          request.updateFailreReason(e.what());
          handle_failed_request(request);
        }
      }

      // if business exception, push to request queue for later processing

      // handle all requests

    }
  }

  void handle_failed_request(req request, RequestState _requestState = nullptr) {
    // handle failed request
    // if exception, retry n times, maybe with exponential backoff
    // if exception, push to request queue for later processing
    try {
      // assert request is failed
      assert(request->status == RequestStatus::FAILED);

      // handle authentication and authorization
      request.updateSate(requestState->failure_reason);
      request.incrementRetryCount();
      request.delayRetry(delaySeconds); // compute delay based on number of retries

      // push to request queue for later processing          
      requestQueue.push(request);
    }
    catch (Exception e) {
      // retry
      // push to request queue for later processing
      return {
        request_id: request->request_id,
        status : RequestStatus::FAILED,
        failure_reason : e.what(),
      };
    }
  }

  // query the request queue for n items
  // @state_machine_state
  vector<shared_ptr<Request>> poll_requests() {
    return requestQueue.poll(requestsPerThread);
  }

  RequestStatus process_reqeust(req request) {
    // process request
    // if exception, retry n times, maybe with exponential backoff
    // if exception, push to request queue for later processing
    try {
      // handle authentication and authorization
      auto& user = await Cognito.maybeRegisterUser({
        email: request->email,
        }); // 
      concurrent{
        // assuming event and channel are already created
        await Backend.registerUserForEvent({
          user_id: user_id,
          event_id : request->event_id,
        });
        auto& event = Backend.getEvent(request->event_id);
        await ChatPlatform.addUserToChannel({
          user_id: user_id,
          channel_id : event->channel_id,
        });
      }
        BackendService.sendEventLinkToUser({
          user_id: user_id,
          event_id : request->event_id,
          });
    });

  }
  catch (Exception e) {
    // retry
    // push to request queue for later processing
    return {
      request_id: request->request_id,
      status : RequestStatus::FAILED,
      failure_reason : e.what(),
    };
  }
}

virtual ~RegistrationService() {
  // TODO Auto-generated destructor stub
}

void registerUser(const std::string& username, const std::string& password) {
  if (username.empty() || password.empty()) {
    throw std::invalid_argument("Username and password cannot be empty");
  }

  if (username.length() < 5 || password.length() < 5) {
    throw std::invalid_argument("Username and password must be at least 5 characters long");
  }

  if (username.length() > 20 || password.length() > 20) {
    throw std::invalid_argument("Username and password must be at most 20 characters long");
  }

  if (username.find_first_of(" ") != std::string::npos) {
    throw std::invalid_argument("Username cannot contain spaces");
  }

  if (password.find_first_of(" ") != std::string::npos) {
    throw std::invalid_argument("Password cannot contain spaces");
  }

  if (username.find_first_of("0123456789") == std::string::npos) {
    throw std::invalid_argument("Username must contain at least one digit");
  }

  if (password.find_first_of("0123456789") == std::string::npos) {
    throw std::invalid_argument("Password must contain at least one digit");
  }

  if (username.find_first_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos) {
    throw std::invalid_argument("Username must contain at least one lowercase letter");
  }

  if (password.find_first_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos) {
    throw std::invalid_argument("Password must contain at least one lowercase letter");
  }

  if (username.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos) {
    throw std::invalid_argument("Username must contain at least one uppercase letter");
  }

  if (password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos) {
    throw std::invalid_argument("Password must contain at least one uppercase letter");
  }

  if (username.find_first_of("!@#$%^&*()_+-=[]{};':,./<>?") == std::string::npos) {
    throw std::invalid_argument("Username must contain at least one special character");
  }

  if (password.find_first_of("!@#$
};